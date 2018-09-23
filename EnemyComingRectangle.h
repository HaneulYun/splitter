#pragma once
#include "EnemyBase.h"

class CEnemyComingRectangle : public CEnemyBase
{
public:
	float m_moveSpeed;
	float m_moveDirection;

	int state;
public:
	CEnemyComingRectangle();
	~CEnemyComingRectangle();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};