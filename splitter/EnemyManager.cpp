#include <algorithm>
#include "stdafx.h"
#include "EnemyManager.h"
#include "GameSceneBase.h"

CEnemyManager::CEnemyManager()
{
	Initialize();
	m_sortTime.InitTimer(1000);
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
	if (m_sortTime.IsValidTimer())
	{
		if (m_sortTime.IsElapseTimer())
		{
			if (m_Enemy.size() > 0) m_Enemy.sort([](CEnemyBase* p, CEnemyBase* q) { return p->m_Point.distance({}) > q->m_Point.distance({}); });
			m_sortTime.InitTimer(1000);
		}
	}

	for (auto itEnemy = std::begin(m_Enemy); itEnemy != std::end(m_Enemy);)
	{
		(*itEnemy)->Pulse();

		auto& bullet = g_pGameScene->m_BulletManager->m_Bullet;

		for (auto itBullet = std::begin(bullet); itEnemy != std::end(m_Enemy) && itBullet != std::end(bullet);)
		{
			if (!(*itEnemy)->hitBox((*itBullet)->m_hitRect)) { ++itBullet; continue; }
			if (!(*itEnemy)->hitPolyton((*itBullet), g_pGameScene->m_matWorld)) { ++itBullet; continue; }

			(*itEnemy)->m_Hp -= (*itBullet)->m_damage;

			if ((*itEnemy)->m_Hp <= 0)
			{
				delete (*itEnemy);
				itEnemy = m_Enemy.erase(itEnemy);
			}

			if (g_pGameScene->m_Player->m_gunType == 4) ++itBullet;
			else if (--((*itBullet)->m_hp) < 0)
			{
				delete (*itBullet);
				itBullet = bullet.erase(itBullet);
			}
			else
			{
				(*itBullet)->m_direction += 1 - 0.4 + 1.8 * (rand() % 200 / 200.0);
				++itBullet;
			}

		}

		if (itEnemy != std::end(m_Enemy)) ++itEnemy;
	}
	return true;
}
void CEnemyManager::Render(Matrix mat)
{
	for (auto& v : m_Enemy)
		v->Render(mat);
}