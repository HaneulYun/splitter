#include "stdafx.h"

CEnemySwirlingPentagon::CEnemySwirlingPentagon()
{
	m_moveSpeed = 0.0f;
	m_rotateSpeed = 0.0f;
	m_moveDirection = 0.0f;
	Initialize();
}

CEnemySwirlingPentagon::~CEnemySwirlingPentagon()
{
	Terminate();
}

bool CEnemySwirlingPentagon::Initialize()
{
	m_eRenderType = eRenderType_Polygon;
	m_Color = RGB(0xff, 0xff, 0xff);

	m_NumPolygon = 5;
	m_Polygon = new POINT[m_NumPolygon];
	for (int i = 0; i < m_NumPolygon; ++i)
		m_Polygon[i] = { LONG(100 * cos(PI * 2 / m_NumPolygon * i)), LONG(100 * sin(PI * 2 / m_NumPolygon * i)) };

	m_rotate = 0.0f;
	m_scale = 1.0f;

	m_moveSpeed = 120;
	m_rotateSpeed = rand() % 2 ? 0.3 : -0.3f;
	m_moveDirection = atan2(-m_Point.y, -m_Point.x) / PI;

	m_Hp = 10;
	m_AddScore = 4;

	return true;
}
void CEnemySwirlingPentagon::Terminate()
{
	g_pSoundManager->Pulse(m_pChannel, 6);
	g_pGameScene->SetShake(0, 0, m_rotate);
	g_pGameScene->m_EffectManager->m_VFX.push_back(new CTearFX(m_Point, 0, 0, m_Color));
	g_pGameScene->m_EffectManager->m_VFX.push_back(new CDestroyFX(m_Point, m_NumPolygon, 0, m_Color));
}
bool CEnemySwirlingPentagon::Pulse()
{
	CEnemyBase::Pulse();

	m_Point.x += g_pSystem->GetTimeStep() * m_moveSpeed * cos(m_moveDirection * PI);
	m_Point.y += g_pSystem->GetTimeStep() * m_moveSpeed * sin(m_moveDirection * PI);

	m_rotate += g_pSystem->GetTimeStep() * m_rotateSpeed;
	return false;
}