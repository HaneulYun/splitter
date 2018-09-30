#include "stdafx.h"
#include "BaseRender.h"
#include "Gdi.h"

CBaseRender::CBaseRender()
{
	m_Mode = false;
	m_bIsHit = false;
	m_pImage = nullptr;
	m_pStr = nullptr;
}

CBaseRender::~CBaseRender()
{
}

void CBaseRender::Render(Matrix matWorld)
{
	Matrix mat;
	POINT* polygon = nullptr;

	if (m_eRenderType)
	{
		polygon = new POINT[m_NumPolygon];
		for (int i = 0; i < m_NumPolygon; ++i)
		{
			mat.Scale(m_scale);
			polygon[i] = mat.Translate(m_Polygon[i]);
			mat.Rotate(m_rotate);
			polygon[i] = mat.Translate(polygon[i]);
			mat.Move(m_Point.x, m_Point.y);
			polygon[i] = mat.Translate(polygon[i]);

			polygon[i] = matWorld.Translate(polygon[i]);

			if (!i)
			{
				m_hitRect = { polygon[i].x, polygon[i].y, polygon[i].x, polygon[i].y };
				if (!m_bIsHit)
					m_bIsHit = true;
			}
			else
			{
				if (m_hitRect.left > polygon[i].x)	m_hitRect.left = polygon[i].x;
				if (m_hitRect.top > polygon[i].y)	m_hitRect.top = polygon[i].y;
				if (m_hitRect.right < polygon[i].x)	m_hitRect.right = polygon[i].x;
				if (m_hitRect.bottom < polygon[i].y)m_hitRect.bottom = polygon[i].y;
			}
		}
		switch (m_eRenderType)
		{
		case CBaseRender::eRenderType_Unknown:
			break;
		case CBaseRender::eRenderType_Polygon:
			g_pGdi->setBrush(m_Color);
			g_pGdi->setPen(1, m_Color);
			Polygon(g_pGdi->m_hdc, polygon, m_NumPolygon);
			break;
		case CBaseRender::eRenderType_Image:
			if (m_pImage == nullptr)
				break;
			m_pImage->Draw(g_pGdi->m_hdc, polygon[0].x, polygon[0].y, polygon[1].x - polygon[0].x, polygon[1].y - polygon[0].y);
			//m_pImage->BitBlt(g_pGdi->m_hdc, polygon[0].x, polygon[0].y, polygon[1].x - polygon[0].x, polygon[1].y - polygon[0].y, 0, 0);
			//BitBlt(g_pGdi->m_hdc, polygon[0].x, polygon[0].y, m_pImage->GetWidth(), m_pImage->GetHeight(), m_pImage->GetDC(), 0, 0, SRCCOPY);
			break;
		case CBaseRender::eRenderType_Font:
			if (m_pStr == nullptr)
				break;;
			if(m_Mode)
				SetBkMode(g_pGdi->m_hdc, TRANSPARENT); 
			SetBkColor(g_pGdi->m_hdc, m_SolidColor);
			SetTextColor(g_pGdi->m_hdc, m_Color);
			g_pGdi->setFont(m_tag);
			TextOut(g_pGdi->m_hdc, polygon[0].x, polygon[0].y, m_pStr, strlen(m_pStr));
			break;
		}
	}
	if(polygon != nullptr)
		delete[] polygon;
}