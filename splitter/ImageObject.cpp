#include "stdafx.h"
#include "ImageObject.h"

CImageObject::CImageObject()
{
}

CImageObject::~CImageObject()
{
}

bool CImageObject::Initialize()
{
	return true;
}
void CImageObject::Terminate()
{

}
bool CImageObject::Pulse()
{
	return true;
}

bool CImageObject::Initialize(char* url, float x, float y, float scale)
{
	m_eRenderType = eRenderType_Image;
	m_pImage = new CImage();
	m_pImage->Load(url);

	m_rotate = 0.0f;
	m_scale = scale;

	m_NumPolygon = 2;
	m_Polygon = new POINT[m_NumPolygon];
	{
		m_Polygon[0] = { -m_pImage->GetWidth() , -m_pImage->GetHeight() };
		m_Polygon[1] = { m_pImage->GetWidth() ,  m_pImage->GetHeight() };
	}

	m_Point = { x, y };
	return true;
}