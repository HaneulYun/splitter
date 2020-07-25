#pragma once
#include "EnemyBase.h"
#include "Timer.h"

class CEnemyManager
{
	CTimer m_sortTime;
public:
	std::list<CEnemyBase*> m_Enemy;
public:
	CEnemyManager();
	~CEnemyManager();

	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render(Matrix mat);
};

