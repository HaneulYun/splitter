#include "stdafx.h"
#include "Gdi.h"
#include "BaseWindow.h"

CGdi::CGdi()
{
}

CGdi::~CGdi()
{
	outPen();
	outBrush();
	outFont();
}

void CGdi::StartDraw()
{
	m_hdcScreen = GetDC(g_pWindow->m_hClientWnd);
	m_hdc = CreateCompatibleDC(m_hdcScreen);
	m_hBitmap = CreateCompatibleBitmap(m_hdcScreen, g_pWindow->m_clientSize.cx, g_pWindow->m_clientSize.cy);
	SelectObject(m_hdc, m_hBitmap);
}

void CGdi::StopDraw()
{
	DeleteObject(m_hBitmap);
	DeleteDC(m_hdc);
	ReleaseDC(g_pWindow->m_hClientWnd, m_hdcScreen);

	m_hdc = NULL;
}

void CGdi::Blt()
{
	BitBlt(m_hdcScreen, 0, 0, g_pWindow->m_clientSize.cx, g_pWindow->m_clientSize.cy, m_hdc, 0, 0, SRCCOPY);
}

HPEN CGdi::setPen(const int cWidth, const COLORREF & color)
{
	HPEN hPen = nullptr;
	for (auto& v : vPen)
		if (v.color == color && v.cWidth == cWidth)
		{
			hPen = v.hPen;
			break;
		}
	if (hPen == nullptr)
	{
		hPen = CreatePen(PS_SOLID, cWidth, color);
		vPen.push_back({});
		vPen.back().hPen = hPen;
		vPen.back().color = color;
		vPen.back().cWidth = cWidth;
	}
	return (HPEN)SelectObject(m_hdc, hPen);
}
HPEN CGdi::setPen(int _tag)
{
	return (HPEN)SelectObject(m_hdc, vPen[_tag].hPen);
}

void CGdi::outPen()
{
	for (auto& v : vPen)
		DeleteObject(v.hPen);
	vPen.clear();
}

HBRUSH CGdi::setBrush(const COLORREF & color)
{
	HBRUSH hBrush = nullptr;
	for (auto& v : vBrush)
		if (v.color == color)
		{
			hBrush = v.hBrush;
			break;
		}
	if (hBrush == nullptr)
	{
		hBrush = CreateSolidBrush(color);
		vBrush.push_back({});
		vBrush.back().hBrush = hBrush;
		vBrush.back().color = color;
	}
	return (HBRUSH)SelectObject(m_hdc, hBrush);
}
HBRUSH CGdi::setBrush(int _tag)
{
	return (HBRUSH)SelectObject(m_hdc, vBrush[_tag].hBrush);
}

void CGdi::outBrush()
{
	for (auto& v : vBrush)
		DeleteObject(v.hBrush);
	vBrush.clear();
}

HFONT CGdi::setFont(const COLORREF& color, const char* url, int _width, int _height, float _angle, bool underLine)
{
	HFONT hFont = nullptr;
	for (auto& v : vFont)
		if (strcmp(v.url, url) == 0 && v.height == _height && v.underLine == underLine)
		{
			hFont = v.hFont;
			break;
		}
	if (hFont == nullptr)
	{
		hFont = CreateFont(_height, _width, _angle, 0, 400, 0, underLine, 0, 1, 0, 0, 0, 0, url);
		vFont.push_back({});
		strcpy(vFont.back().url, url);
		vFont.back().hFont = hFont;
		vFont.back().width = _width;
		vFont.back().height = _height;
		vFont.back().angle = _angle;
		vFont.back().underLine = underLine;
	}
	return (HFONT)SelectObject(m_hdc, hFont);
}
HFONT CGdi::setFont(int _tag)
{
	return (HFONT)SelectObject(m_hdc, vFont[_tag].hFont);
}
int CGdi::getFontTag(const char* url, int _height, bool underLine)
{
	HFONT hFont = nullptr;
	for (int i = 0; i < vFont.size(); ++i)
		if (strcmp(vFont[i].url, url) == 0 && vFont[i].height == _height && vFont[i].underLine == underLine)
			return i;
}
void CGdi::outFont()
{
	for (auto& v : vFont)
		DeleteObject(v.hFont);
	vFont.clear();
}