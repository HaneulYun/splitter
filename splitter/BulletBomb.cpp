#include "stdafx.h"
#include "Bulletbomb.h"
#include "WndSystem.h"
#include "GameSceneBase.h"

CBulletBomb::CBulletBomb(float direction, float damage)
{
	m_direction = direction + (rand() % 100 / 5000.0) - 0.01;
	m_speed = 2000;
	m_damage = damage;

	Initialize();
}


CBulletBomb::~CBulletBomb()
{
	Terminate();
}

bool CBulletBomb::Initialize()
{
	m_eRenderType = eRenderType_Polygon;
	m_Color = RGB(0xff, 0xff, 0xff);

	m_Point = { 0, 0 };
	m_rotate = m_direction;
	m_scale = 1.0;


	m_NumPolygon = 8;
	m_Polygon = new POINT[m_NumPolygon];
	{
		m_Polygon[0] = { 10, 6 };
		m_Polygon[1] = { 60, 6 };
		m_Polygon[2] = { 10, 15 };
		m_Polygon[3] = { -40, 6 };
		m_Polygon[4] = { -40, -6 };
		m_Polygon[5] = { 10, -15 };
		m_Polygon[6] = { 60, -6 };
		m_Polygon[7] = { 10, -6 };
	}

	return true;
}
void CBulletBomb::Terminate()
{
	if (m_activeState)
		g_pGameScene->m_EffectManager->m_VFX.push_back(new CDestroyFX(m_Point, 6, 70, m_Color));
}
bool CBulletBomb::Pulse()
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
