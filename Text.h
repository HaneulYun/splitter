#pragma once
#include "BaseObject.h"

class CText : public CBaseObject
{
public:
	int m_MaxStrlen;
public:
	CText();
	~CText();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;

	bool FontInitialize(int strlen, char* url, int _height, int _width, bool _underLine = false);
	bool ObjectInitialize(int x, int y, COLORREF color, COLORREF bk, int mode);
	bool Pulse(char* str);
};

#define WIDTH_NORMALIZE(w, x) (-w/2+w*(x/1280.f))
#define HEIGHT_NORMALIZE(h, y) (-h/2+h*(y/720.f))