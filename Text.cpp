#include "stdafx.h"
#include "Text.h"
#include "Gdi.h"

CText::CText()
{
	m_pStr = nullptr;
	Initialize();
}

CText::~CText()
{
	Terminate();
}

bool CText::Initialize()
{
	return true;
}
bool CText::FontInitialize(int strlen, char* url, int _height, int _width, bool _underLine)
{
	m_eRenderType = eRenderType_Font;
	m_Color = RGB(0xff, 0xff, 0xff);

	m_pStr = new char[strlen + 1];
	strcpy(m_pStr, "");

	g_pGdi->setFont(0, url, _width, _height, 0, _underLine);
	m_tag = g_pGdi->getFontTag(url, _height, _underLine);

	m_rotate = 0.0f;
	m_scale = 1.0f;

	return true;
}
void CText::resetX(int x)
{
	m_Point.x = x;
	m_Polygon[0] = { LONG(m_Point.x), LONG(m_Point.y) };
	m_Polygon[1] = { LONG(m_Point.x + 1), LONG(m_Point.y + 1) };
}
void CText::resetY(int y)
{
	m_Point.y = y;
	m_Polygon[0] = { LONG(m_Point.x), LONG(m_Point.y) };
	m_Polygon[1] = { LONG(m_Point.x + 1), LONG(m_Point.y + 1) };
}
bool CText::ObjectInitialize(int x, int y, COLORREF color, COLORREF bk, int mode)
{
	m_Point.x = x;
	m_Point.y = y;
	m_Color = color;
	m_SolidColor = bk;
	m_Mode = mode;

	m_NumPolygon = 2;
	m_Polygon = new POINT[m_NumPolygon];
	{
		m_Polygon[0] = { LONG(m_Point.x), LONG(m_Point.y) };
		m_Polygon[1] = { LONG(m_Point.x + 1), LONG(m_Point.y + 1) };
	}
	return true;
}
void CText::Terminate()
{
}

bool CText::Pulse()
{
	return false;
}
bool CText::Pulse(char* str)
{
	strcpy(m_pStr, str);
	return false;
}