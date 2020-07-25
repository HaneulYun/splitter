#include "stdafx.h"
#include "AfterimageFX.h"

CAfterimageFX::CAfterimageFX(CBaseObject* obj, COLORREF color, float delay)
{
	m_eRenderType = eRenderType_Polygon;
	m_oriColor = m_Color = color;

	m_NumPolygon = obj->m_NumPolygon;
	m_Polygon = new POINT[m_NumPolygon];
	for (int i = 0; i < m_NumPolygon; ++i)
		m_Polygon[i] = { obj->m_Polygon[i].x, obj->m_Polygon[i].y };

	m_scale = obj->m_scale;
	m_Point = obj->m_Point;
	m_rotate = obj->m_rotate;

	m_delay = delay;

	m_Timer.InitTimer(m_delay);
}

CAfterimageFX::~CAfterimageFX()
{
	if (m_Polygon) { delete[] m_Polygon; m_Polygon = nullptr; }
}

bool CAfterimageFX::Initialize()
{
	return false;
}
void CAfterimageFX::Terminate()
{

}
bool CAfterimageFX::Pulse()
{
	if (m_Timer.IsValidTimer())
	{
		float ratio = 1.0 / m_delay * (GetTickCount() - m_Timer.m_dwOldTime);
		ratio = 1 - ratio;
		m_Color = RGB((0x0000ff & m_oriColor) * ratio, ((0x00ff00 & m_oriColor) >> 8) * ratio, ((0xff0000 & m_oriColor) >> 16) * ratio);
		if (m_Timer.IsElapseTimer())
		{
			return true;
		}
	}
	return false;
}