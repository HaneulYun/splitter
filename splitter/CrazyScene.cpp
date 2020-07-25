#include "stdafx.h"
#include "CrazyScene.h"
#include "EnemyComingRectangle.h"
#include "EnemyRotatingRectangle.h"
#include "EnemyRotatingTwoTriangleUp.h"
#include "EnemyRotatingTriangleHavingShield.h"




CrazyScene::CrazyScene()
{
	g_pSoundManager->Pulse(m_pChannel, 1);
	m_spawnE0101.InitTimer(350);
	OriginalShakeLevel = g_pSystem->m_abc;
	g_pSystem->m_abc = 5.0;
}


CrazyScene::~CrazyScene()
{
	g_pSoundManager->ChannelStop(m_pChannel);
	g_pSystem->m_abc = OriginalShakeLevel;
	Terminate();
}

bool CrazyScene::Pulse()
{
	if (m_spawnE0101.IsValidTimer())
		if (m_spawnE0101.IsElapseTimer())
		{
			m_EnemyManager->m_Enemy.push_back(new CEnemyComingRectangle());
			m_spawnE0101.InitTimer(350);
		}
	if (m_Score > m_spawnE0102)
	{
		m_EnemyManager->m_Enemy.push_back(new CEnemyRotatingRectangle());
		m_spawnE0102 += 20;
	}
	if (m_Score > m_spawnE0103)
	{
		m_EnemyManager->m_Enemy.push_back(new CEnemyRotatingTwoTriangleUp());
		m_spawnE0103 += 35;
	}
	if (m_Score > m_spawnE0105)
	{
		m_EnemyManager->m_Enemy.push_back(new CEnemyRotatingTriangleHavingShield());
		m_spawnE0105 += 50;
	}
	CGameSceneBase::Pulse();
	return true;
}
