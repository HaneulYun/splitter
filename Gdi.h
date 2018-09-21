#pragma once

#define g_pGdi CGdi::Instance()

struct _HPEN
{
	HPEN hPen;
	COLORREF color;
	int cWidth;
};
struct _HBRUSH
{
	HBRUSH hBrush;
	COLORREF color;
};
struct _HFONT
{
	HFONT hFont;
	char url[30];
	int width;
	int height;
	float angle;
	bool underLine;
};
struct _CImagae
{
	CImage img;
	char url[30];
};

class CGdi
{
public:
	HDC m_hdcScreen, m_hdc;
	HBITMAP m_hBitmap;

	std::vector<_HPEN> vPen;
	std::vector<_HBRUSH> vBrush;
	std::vector<_HFONT> vFont;
	std::vector<_CImagae> vImage;

	static CGdi* instance;
public:
	CGdi();
	~CGdi();

	static CGdi* Instance()
	{
		if (instance == nullptr)
			instance = new CGdi();
		return instance;
	}

	void StartDraw();
	void StopDraw();
	void Blt();

	HPEN setPen(const int cWidth, const COLORREF& color);
	HBRUSH setBrush(const COLORREF& color);
	HFONT setFont(const COLORREF& color, const char* url, int _width, int _height, float _angle, bool underLine = 0);

	HPEN setPen(int _tag);
	HBRUSH setBrush(int _tag);
	HFONT setFont(int _tag);

	int getFontTag(const char* url, int _height, bool underLine = 0);

	void outPen();
	void outBrush();
	void outFont();
};