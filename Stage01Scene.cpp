#include "stdafx.h"
#include "Stage01Scene.h"
#include "SoundManager.h"
#include "EnemyComingRectangle.h"
#include "EnemyRotatingRectangle.h"
#include "EnemyRotatingTwoTriangleUp.h"
#include "EnemyRotatingTriangleHavingShield.h"

#include "RedLineFX.h"

#include "EnemySwirlingPentagon.h"

Stage01Scene::Stage01Scene()
{
	g_pSoundManager->Pulse(m_pChannel, 2);
	m_spawnE0101.InitTimer(350);
	m_spawnE0102 = 100;
	m_spawnE0103 = 150;
	m_spawnE0105 = 200;
	//m_spawnE0106 = 0;
	m_spawnE0106 = 350;
	//m_spawnE0107 = 0;
	m_spawnE0107 = 450;
	m_spawnE0108 = 450;
	m_spawnE0110 = 600;
}

Stage01Scene::~Stage01Scene()
{
	g_pSoundManager->ChannelStop(m_pChannel);
	Terminate();
}

bool Stage01Scene::Pulse()
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
	if (m_Score > m_spawnE0106)
	{
		m_EffectManager->m_VFX.push_back(new CRedLineFX());
		m_spawnE0106 += 90;
	}
	if (m_Score > m_spawnE0107)
	{
		m_EnemyManager->m_Enemy.push_back(new CEnemySwirlingPentagon());
		m_spawnE0107 += 90;
	}
	//if (m_Score > m_spawnE0108)
	//{
	//	m_EnemyManager->m_Enemy.push_back(new CEnemyCorpsBossRectangle());
	//	m_spawnE0108 += 90;
	//}
	//if (m_Score > m_spawnE0110)
	//{
	//	m_EnemyManager->m_Enemy.push_back(new CEnemyHalfSegment());
	//	m_spawnE0110 += 180;
	//}
	CGameSceneBase::Pulse();
	return true;
}