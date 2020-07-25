#include "stdafx.h"
#include "EffectLineFX.h"
#include "WndSystem.h"


CEffectLineFX::CEffectLineFX(Vector pt, float distance, COLORREF color)
{
	m_eRenderType = eRenderType_Polygon;
	m_Color = color;

	m_Distance = distance;
	m_NumPolygon = 4;
	m_Polygon = new POINT[m_NumPolygon];
	m_TargetPolygon = new POINT[m_NumPolygon];
	{
		m_TargetPolygon[0] = m_Polygon[0] = { LONG(-8000), LONG(-distance) };
		m_TargetPolygon[1] = m_Polygon[1] = { LONG(-8000), LONG( distance) };
		m_TargetPolygon[2] = m_Polygon[2] = { LONG( 8000), LONG( distance) };
		m_TargetPolygon[3] = m_Polygon[3] = { LONG( 8000), LONG(-distance) };
	}

	m_scale = 1.0f;
	m_Point = pt;
	m_rotate = rand() % 200 / 100.0;

	m_InnerRatio = 0.0f;
	m_OuterRatio = 0.0f;

	m_Timer.InitTimer(400);
}


CEffectLineFX::~CEffectLineFX()
{
}

bool CEffectLineFX::Initialize()
{
	return false;
}
void CEffectLineFX::Terminate()
{

}
bool CEffectLineFX::Pulse()
{
	if (m_Timer.IsValidTimer())
	{
		float ratio = 1.0 / 400 * (GetTickCount() - m_Timer.m_dwOldTime);
		float rInner = 1 - sin(ratio * PI / 2);
		//float rOuter = sin(PI * (1.5 + ratio / 2)) + 1;
		//float rOuter = ratio;
		for (int i = 0; i < m_NumPolygon; ++i)
		{
			m_Polygon[i] = { LONG(m_TargetPolygon[i].x * 1.f), LONG(m_TargetPolygon[i].y * rInner) };
		}
		if (m_Timer.IsElapseTimer())
		{
			return true;
		}
	}
	return false;
}
