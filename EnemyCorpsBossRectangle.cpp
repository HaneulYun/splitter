#include "stdafx.h"
#include "EnemyCorpsBossRectangle.h"
#include "GameSceneBase.h"
#include "AfterimageFX.h"

CEnemyCorpsBossRectangle::CEnemyCorpsBossRectangle()
{
	m_moveSpeed = 0.0f;
	m_rotateSpeed = 0.0f;
	m_moveDirection = 0.0f;
	Initialize();
}

CEnemyCorpsBossRectangle::~CEnemyCorpsBossRectangle()
{
	Terminate();
}

bool CEnemyCorpsBossRectangle::Initialize()
{
	m_eRenderType = eRenderType_Polygon;
	m_Color = RGB(0xff, 0xff, 0xff);

	m_NumPolygon = 4;
	m_Polygon = new POINT[m_NumPolygon];
	{
		m_Polygon[0] = { -100, -100 };
		m_Polygon[1] = { -100,  100 };
		m_Polygon[2] = { 100,  100 };
		m_Polygon[3] = { 100, -100 };
	}

	m_rotate = 0.0f;
	m_scale = 1.0f;

	m_moveSpeed = 90;
	m_rotateSpeed = rand() % 2 ? 0.2 : -0.2f;
	m_moveDirection = atan2(-m_Point.y, -m_Point.x) / PI;

	m_Hp = 20;
	m_AddScore = 6;

	m_timerAfterEffect.InitTimer(50);

	return true;
}
void CEnemyCorpsBossRectangle::Terminate()
{
	g_pSoundManager->Pulse(m_pChannel, 6);
	g_pGameScene->SetShake(0, 0, m_rotate);
	g_pGameScene->m_EffectManager->m_VFX.push_back(new CTearFX(m_Point, 0, 0, m_Color));
	g_pGameScene->m_EffectManager->m_VFX.push_back(new CDestroyFX(m_Point, m_NumPolygon, 0, m_Color));
}
bool CEnemyCorpsBossRectangle::Pulse()
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