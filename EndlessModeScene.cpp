#include "stdafx.h"

EndlessModeScene::EndlessModeScene()
{
	g_pSoundManager->Pulse(m_pChannel, 1);
	m_spawnE0101.InitTimer(350);
}

EndlessModeScene::~EndlessModeScene()
{
	g_pSoundManager->ChannelStop(m_pChannel);
	Terminate();
}

bool EndlessModeScene::Pulse()
{
	if (m_spawnE0101.IsValidTimer())
		if (m_spawnE0101.IsElapseTimer())
		{
			m_EnemyManager->m_Enemy.push_back(new CEnemyComingRectangle());
			m_spawnE0101.InitTimer(350);
		}
	CGameSceneBase::Pulse();
	return true;
}