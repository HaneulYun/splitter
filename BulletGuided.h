#pragma once
#include "BulletBase.h"
#include "Timer.h"

class CBulletGuided : public CBulletBase
{
	int cnt;
	bool left;
	bool right;

	CTimer timerLeft;
	CTimer timerRight;
public:
	CBulletGuided(float direction);
	~CBulletGuided();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};

