#include "stdafx.h"

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
	for (int i = 0; i < m_Bullet.size(); ++i)
		if (m_Bullet[i]->Pulse())
		{
			delete m_Bullet[i];
			m_Bullet.erase(m_Bullet.begin() + i);
		}
	return true;
}
void CBulletManager::Render(Matrix mat)
{
	for (auto& v : m_Bullet)
		v->Render(mat);
}