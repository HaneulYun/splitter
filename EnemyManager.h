#pragma once
#include "EnemyBase.h"

class CEnemyManager
{
public:
	std::deque<CEnemyBase*> m_Enemy;
public:
	CEnemyManager();
	~CEnemyManager();

	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render(Matrix mat);
};

