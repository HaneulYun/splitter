#include "stdafx.h"
#include "BulletManager.h"

CBulletManager::CBulletManager()
{
	Initialize();
}

CBulletManager::~CBulletManager()
{
	Terminate();
}

bool CBulletManager::Initialize()
{
	m_Bullet.clear();
	return true;
}
void CBulletManager::Terminate()
{
	for (auto& v : m_Bullet)
		delete v;
	m_Bullet.clear();
}
bool CBulletManager::Pulse()
{
	for (auto iter = std::begin(m_Bullet); iter != std::end(m_Bullet);)
	{
		auto& bullet = *iter;
		if (!bullet->Pulse())
		{
			++iter;
			continue;
		}

		delete bullet;
		iter = m_Bullet.erase(iter);
	}
	return true;
}
void CBulletManager::Render(Matrix mat)
{
	for (auto& v : m_Bullet)
		v->Render(mat);
}