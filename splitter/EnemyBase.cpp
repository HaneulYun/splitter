#include "stdafx.h"
#include "EnemyBase.h"
#include "GameSceneBase.h"

CEnemyBase::CEnemyBase()
{
	m_type = 0;

	float radius = sqrt(pow(g_pGameScene->m_worldRect.right, 2) + pow(g_pGameScene->m_worldRect.bottom, 2));
	float randValue = rand() % 200 / 100.0;
	m_Point = { float(radius * cos(randValue * PI)), float(radius * sin(randValue * PI)) };

	m_afterimageTimer.InitTimer(20);
}

CEnemyBase::~CEnemyBase()
{
	g_pGameScene->m_Score += m_AddScore;
}

bool CEnemyBase::Pulse()
{
	if (m_afterimageTimer.IsValidTimer())
		if (m_afterimageTimer.IsElapseTimer())
		{
			//g_pGameScene->m_EffectManager->m_VFX.push_back(new CAfterimageFX(*this, m_Color));
			m_afterimageTimer.InitTimer(50);
		}
	return true;
}