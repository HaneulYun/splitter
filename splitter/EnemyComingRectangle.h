#pragma once
#include "Timer.h"
#include "EnemyBase.h"

class CEnemyComingRectangle : public CEnemyBase
{
public:
	float m_moveSpeed;
	float m_moveDirection;
	CTimer m_timerAfterEffect;

	int state;
public:
	CEnemyComingRectangle();
	~CEnemyComingRectangle();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};