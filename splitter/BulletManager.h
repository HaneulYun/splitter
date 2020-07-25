#pragma once
#include "BulletBase.h"

class CBulletManager
{
public:
	std::list<CBulletBase*> m_Bullet;
public:
	CBulletManager();
	~CBulletManager();

	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render(Matrix mat);
};