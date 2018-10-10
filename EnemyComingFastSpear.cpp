#include "stdafx.h"
#include "EnemyComingFastSpear.h"
#include "GameSceneBase.h"
#include "AfterimageFX.h"

CEnemyComingFastSpear::CEnemyComingFastSpear(Vector pt)
{
	m_moveSpeed = 0.0f;
	m_moveDirection = 0.0f;
	m_Point = pt;
	Initialize();
}

CEnemyComingFastSpear::~CEnemyComingFastSpear()
{
	Terminate();
}

bool CEnemyComingFastSpear::Initialize()
{
	m_eRenderType = eRenderType_Polygon;
	m_Color = RGB(0xff, 0x00, 0x00);

	m_NumPolygon = 4;
	m_Polygon = new POINT[m_NumPolygon];
	{
		m_Polygon[0] = { 200, 0 };
		m_Polygon[1] = { -100, -50 };
		m_Polygon[2] = { -50,  0 };
		m_Polygon[3] = { -100, 50 };
	}

	m_rotate = 0.0f;
	m_scale = 1.0f;

	m_moveSpeed = 2500;
	m_rotate = m_moveDirection = atan2(-m_Point.y, -m_Point.x) / PI;

	m_Hp = 4;
	m_AddScore = 12;

	m_timerAfterEffect.InitTimer(50);

	return true;
}
void CEnemyComingFastSpear::Terminate()
{
	g_pSoundManager->Pulse(m_pChannel, 7);
	g_pGameScene->SetShake(0, 0, m_rotate);
	g_pGameScene->m_EffectManager->m_VFX.push_back(new CTearFX(m_Point, 300, 6, m_Color));
	g_pGameScene->m_EffectManager->m_VFX.push_back(new CDestroyFX(m_Point, m_NumPolygon, 300, m_Color));
}
bool CEnemyComingFastSpear::Pulse()
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
	return false;
}