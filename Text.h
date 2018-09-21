#pragma once

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

