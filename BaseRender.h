#pragma once
class CBaseRender
{
public:
	enum eRenderType
	{
		eRenderType_Unknown,
		//eRenderType_Sprite,
		eRenderType_Polygon,
		eRenderType_Image,
		eRenderType_Font,
	};
public:
	eRenderType m_eRenderType;
	// general data
	Vector m_Point;
	COLORREF m_Color;
	COLORREF m_SolidColor;

	float m_scale;
	float m_rotate;

	RECT m_hitRect;
	bool m_bIsHit;

	// eRenderType_Polygon
	union
	{
		int m_NumPolygon;
		int m_Mode;	// FontMode
	};
	POINT* m_Polygon;

	// integrated Image & Font
	int m_tag;

	// eRenderType_Image
	CImage* m_pImage;

	// eRenderType_Font
	char* m_pStr;

public:
	CBaseRender();
	virtual ~CBaseRender();

	virtual bool Initialize() = 0;
	virtual void Terminate() = 0;
	virtual bool Pulse() = 0;
	virtual void Render(Matrix matWorld);
};

