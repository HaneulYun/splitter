#include "stdafx.h"
#include "EnemyManager.h"
#include "GameSceneBase.h"

CEnemyManager::CEnemyManager()
{
	Initialize();
}

CEnemyManager::~CEnemyManager()
{
}

bool CEnemyManager::Initialize()
{
	return true;
}
void CEnemyManager::Terminate()
{

}
bool CEnemyManager::Pulse()
{
	for (int i = 0; i < m_Enemy.size(); ++i)
	{
		if (m_Enemy[i] == nullptr)
		{
			m_Enemy.erase(m_Enemy.begin() + i);
			--i;
			continue;
		}
		m_Enemy[i]->Pulse();
		for (int j = 0; j < g_pGameScene->m_BulletManager->m_Bullet.size() && i < m_Enemy.size(); ++j)
			if (m_Enemy[i] == nullptr)
			{
				m_Enemy.erase(m_Enemy.begin() + i);
				--i;
				continue;
			}
			else if (m_Enemy[i]->hitBox(g_pGameScene->m_BulletManager->m_Bullet[j]->m_hitRect))
			{
				if (m_Enemy[i]->hitPolyton(g_pGameScene->m_BulletManager->m_Bullet[j], g_pGameScene->m_matWorld))
				{
					delete g_pGameScene->m_BulletManager->m_Bullet[j];
					g_pGameScene->m_BulletManager->m_Bullet.erase(g_pGameScene->m_BulletManager->m_Bullet.begin() + j);
					if (--m_Enemy[i]->m_Hp == 0)
					{
						delete m_Enemy[i];
						m_Enemy.erase(m_Enemy.begin() + i);
						--i;
					}
				}
			}
	}
	return true;
}
void CEnemyManager::Render(Matrix mat)
{
	for (auto& v : m_Enemy)
		if(v != nullptr)
			v->Render(mat);
}