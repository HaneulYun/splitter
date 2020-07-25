#include "stdafx.h"
#include "EnemyHalfSegment.h"
#include "GameSceneBase.h"
#include "AfterimageFX.h"

CEnemyHalfSegment::CEnemyHalfSegment()
{
	m_moveSpeed = 0.0f;
	m_rotateSpeed = 0.0f;
	m_moveDirection = 0.0f;
	Initialize();
}

CEnemyHalfSegment::~CEnemyHalfSegment()
{
	Terminate();
}

bool CEnemyHalfSegment::Initialize()
{
	m_eRenderType = eRenderType_Polygon;
	m_Color = RGB(0xff, 0xff, 0xff);

	m_NumPolygon = 3;
	m_Polygon = new POINT[m_NumPolygon];
	for (int i = 0; i < m_NumPolygon; ++i)
		m_Polygon[i] = { LONG(100 * cos(PI * 2 / m_NumPolygon * i)), LONG(100 * sin(PI * 2 / m_NumPolygon * i)) };

	m_rotate = 0.0f;
	m_scale = 1.0f;

	m_moveSpeed = 120;
	m_rotateSpeed = rand() % 2 ? 0.3 : -0.3f;
	m_moveDirection = atan2(-m_Point.y, -m_Point.x) / PI;

	m_Hp = 25;
	m_AddScore = 4;

	m_timerAfterEffect.InitTimer(50);

	return true;
}
void CEnemyHalfSegment::Terminate()
{
	for (int i = 0; i < g_pGameScene->m_EnemyManager->m_Enemy.size(); ++i)
		for (int j = 0; j < 3; ++j)
			if (g_pGameScene->m_EnemyManager->m_Enemy[i] == m_pShield[j])
			{
				delete g_pGameScene->m_EnemyManager->m_Enemy[i];
				g_pGameScene->m_EnemyManager->m_Enemy[i] = nullptr;
				--i;
				break;
			}
	g_pSoundManager->Pulse(m_pChannel, 6);
	g_pGameScene->SetShake(150, 15, m_rotate);
	g_pGameScene->m_EffectManager->m_VFX.push_back(new CTearFX(m_Point, 600, 15, m_Color));
	g_pGameScene->m_EffectManager->m_VFX.push_back(new CDestroyFX(m_Point, m_NumPolygon * 2, 600, m_Color));
}
bool CEnemyHalfSegment::Pulse()
{
	CEnemyBase::Pulse();

	if (m_timerAfterEffect.IsElapseTimer()) {
		if (!m_timerAfterEffect.IsValidTimer()) {
			g_pGameScene->m_EffectManager->m_VFX.push_back(new CAfterimageFX(this, m_Color, 300));
			m_timerAfterEffect.InitTimer(50);
		}
	}

	m_Point.x += g_pSystem->GetTimeStep() * m_moveSpeed * cos(m_moveDirection * PI);
	m_Point.y += g_pSystem->GetTimeStep() * m_moveSpeed * sin(m_moveDirection * PI);

	m_rotate += g_pSystem->GetTimeStep() * m_rotateSpeed;
	return false;
}