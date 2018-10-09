#pragma once
#include "EnemyBase.h"

class CEnemyComingFastSpear : public CEnemyBase
{
public:
	float m_moveSpeed;
	float m_moveDirection;
	CTimer m_timerAfterEffect;

public:
	CEnemyComingFastSpear();
	~CEnemyComingFastSpear();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};