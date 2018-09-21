#include "stdafx.h"


CButtonObject::CButtonObject()
{
}


CButtonObject::~CButtonObject()
{
}

bool CButtonObject::Initialize()
{
	return true;
}
void CButtonObject::Terminate()
{

}
bool CButtonObject::Pulse()
{

	return true;
}

bool CButtonObject::Initialize(float x, float y, COLORREF RGB, eButtonType eType)
{
	m_eRenderType = eRenderType_Polygon;
	m_Color = RGB;

	switch (eType)
	{
	case CButtonObject::eButtonType_scroll:
		m_NumPolygon = 4;
		m_Polygon = new POINT[m_NumPolygon];
		{
			m_Polygon[0] = { -700, -20 };
			m_Polygon[1] = { 700,  -20 };
			m_Polygon[2] = { 700,  20 };
			m_Polygon[3] = { -700, 20 };
		}
		break;
	case CButtonObject::eButtonType_button:
		m_NumPolygon = 4;
		m_Polygon = new POINT[m_NumPolygon];
		{
			m_Polygon[0] = { -50, -50 };
			m_Polygon[1] = { 50,  -50 };
			m_Polygon[2] = { 50,  50 };
			m_Polygon[3] = { -50, 50 };
		}
		break;
	default:
		break;
	}

	m_Point.x = x;
	m_Point.y = y;

	m_scale = 1.0f;
	m_rotate = 0.0f;
	return true;
}

