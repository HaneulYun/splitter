#pragma once
#include "GameSceneBase.h"

class Stage01Scene : public CGameSceneBase
{
public:
	CTimer m_spawnE0101;
	int m_spawnE0102;
	int m_spawnE0103;
	int m_spawnE0105;
	int m_spawnE0106;
	int m_spawnE0107;
	int m_spawnE0108;
	int m_spawnE0110;
public:
	Stage01Scene();
	~Stage01Scene();

	bool Pulse();
};