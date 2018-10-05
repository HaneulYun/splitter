#include "stdafx.h"
#include "BulletSprinkle.h"
#include "WndSystem.h"
#include "GameSceneBase.h"

CBulletSprinkle::CBulletSprinkle(float direction)
{
	m_direction = direction + (rand() % 100 / 1000.0) - 0.05;
	m_speed = 4000;
	m_damage = 0.4;

	Initialize();
}

CBulletSprinkle::~CBulletSprinkle()
{
	Terminate();
}

bool CBulletSprinkle::Initialize()
{
	m_eRenderType = eRenderType_Polygon;
	m_Color = RGB(0xff, 0xff, 0xff);

	m_Point = { 0, 0 };
	m_rotate = m_direction;
	m_scale = 0.7;


	m_NumPolygon = 4;
	m_Polygon = new POINT[m_NumPolygon];
	{
		m_Polygon[0] = { 0,  -8 };
		m_Polygon[1] = { -56, 0 };
		m_Polygon[2] = { 0,   8 };
		m_Polygon[3] = { 56,  0 };
	}

	return true;
}
void CBulletSprinkle::Terminate()
{
	if (m_activeState)
		g_pGameScene->m_EffectManager->m_VFX.push_back(new CDestroyFX(m_Point, 6, 70, m_Color));
}
bool CBulletSprinkle::Pulse()
{
	if (!m_activeState) m_activeState = true;

	m_Point.x += g_pSystem->GetTimeStep() * m_speed * cos(m_direction * PI);
	m_Point.y += g_pSystem->GetTimeStep() * m_speed * sin(m_direction * PI);

	POINT pt = { m_Point.x, m_Point.y };
	pt = g_pSystem->m_pCurProcess->GetMatrix().Translate(pt);

	if (pt.x + 60 < 0 || pt.y + 60 < 0 ||
		pt.x - 60 > +g_pWindow->m_clientSize.cx || pt.y - 60 > +g_pWindow->m_clientSize.cy)
		return true;
	return false;
}