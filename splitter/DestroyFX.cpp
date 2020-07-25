#include "stdafx.h"
#include "DestroyFX.h"

CDestroyFX::CDestroyFX(Vector pt, int polyAngle, float distance, COLORREF color)
{
	m_eRenderType = eRenderType_Polygon;
	m_Color = color;

	m_Distance = distance;
	m_NumPolygon = (polyAngle + 1) * 2;
	m_Polygon = new POINT[m_NumPolygon];
	m_TargetPolygon = new POINT[m_NumPolygon];
	for (int i = 0; i < polyAngle + 1; ++i)
	{
		m_Polygon[i] = { 0, 0 };
		m_Polygon[polyAngle + 1 + i] = { 0, 0 };
		m_TargetPolygon[i] = { LONG(m_Distance * cos(PI * 2 / polyAngle * i)), LONG(m_Distance * sin(PI * 2 / polyAngle * i)) };
		m_TargetPolygon[polyAngle + 1 + i] = { LONG(m_Distance * cos(PI * 2 / polyAngle * (polyAngle - i))), LONG(m_Distance * sin(PI * 2 / polyAngle * (polyAngle - i))) };
	}

	m_scale = 1.0f;
	m_Point = pt;
	m_rotate = rand() % 200 / 100.0;

	m_InnerRatio = 0.0f;
	m_OuterRatio = 0.0f;

	m_Timer.InitTimer(400);
}

CDestroyFX::~CDestroyFX()
{
	if (m_TargetPolygon) delete[] m_TargetPolygon;
}

bool CDestroyFX::Initialize()
{
	return false;
}
void CDestroyFX::Terminate()
{

}
bool CDestroyFX::Pulse()
{
	if (m_Timer.IsValidTimer())
	{
		float ratio = 1.0 / 400 * (GetTickCount() - m_Timer.m_dwOldTime);
		float rInner = sin(ratio * PI / 2);
		float rOuter = sin(PI * (1.5 + ratio / 2)) + 1;
		//float rOuter = ratio;
		for (int i = 0; i < m_NumPolygon / 2; ++i)
		{
			m_Polygon[i] = { LONG(m_TargetPolygon[i].x * rInner), LONG(m_TargetPolygon[i].y * rInner) };
			m_Polygon[m_NumPolygon / 2 + i] = { LONG(m_TargetPolygon[i].x * rOuter), LONG(m_TargetPolygon[i].y * rOuter) };
		}
		if (m_Timer.IsElapseTimer())
		{
			return true;
		}
	}
	return false;
}