#include "stdafx.h"

CTearElement::CTearElement(Vector pt, int polyAngle, float distance, COLORREF color)
{
	m_eRenderType = eRenderType_Polygon;
	m_Color = color;

	m_OldDistance = rand() % int(distance / 2) + distance / 2;
	m_NumPolygon = polyAngle;
	m_Polygon = new POINT[m_NumPolygon];
	m_TargetPolygon = new POINT[m_NumPolygon];
	for (int i = 0; i < m_NumPolygon; ++i)
		m_TargetPolygon[i] = m_Polygon[i] = { LONG(m_OldDistance * cos(PI / m_NumPolygon * 2 * i)), LONG(m_OldDistance * sin(PI / m_NumPolygon * 2 * i)) };

	m_scale = 1.0f;
	m_Point = pt;
	m_rotate = 0.0;
	m_MyRotate = rand() % 200 / 100.0;

	m_OldRatioX = 1.0;
	m_OldRatioY = rand() % 10 / (distance / 2);

	m_Timer.InitTimer(600);
}

CTearElement::~CTearElement()
{
	
}

bool CTearElement::Initialize()
{
	return true;
}

void CTearElement::Terminate()
{

}

bool CTearElement::Pulse()
{
	if (m_Timer.IsValidTimer())
	{
		float ratio = 1.0 / 600 * (GetTickCount() - m_Timer.m_dwOldTime);
		m_CurRatioX = m_OldRatioX - sin(m_OldRatioX * ratio * PI / 2);
		m_CurRatioY = m_OldRatioY - m_OldRatioY * ratio;
		m_CurDistance = m_OldDistance + m_OldDistance * sin(m_OldRatioX * ratio * PI / 2);

		Matrix mat;
		for (int i = 0; i < m_NumPolygon; ++i)
		{
			mat.Scale(m_CurRatioX, m_CurRatioY);
			m_Polygon[i] = mat.Translate(m_TargetPolygon[i]);
			mat.Rotate(m_MyRotate);
			m_Polygon[i] = mat.Translate(m_Polygon[i]);
			mat.Move(m_CurDistance * cos(m_MyRotate*PI), m_CurDistance * sin(m_MyRotate*PI));
			m_Polygon[i] = mat.Translate(m_Polygon[i]);
		}	
		if (m_Timer.IsElapseTimer())
		{
			return true;
		}
	}
	return false;
}