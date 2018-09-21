#pragma once

class EndlessModeScene : public CGameSceneBase
{
public:
	CTimer m_spawnE0101;
public:
	EndlessModeScene();
	~EndlessModeScene();

	bool Pulse();
};