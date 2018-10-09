#pragma once
#include "EnemyBase.h"

class CEnemyRotatingTwoTriangleUp : public CEnemyBase
{
public:
	float m_moveSpeed;
	float m_rotateSpeed;
	float m_moveDirection;
	CTimer m_timerAfterEffect;
public:
	CEnemyRotatingTwoTriangleUp();
	~CEnemyRotatingTwoTriangleUp();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};