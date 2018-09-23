#pragma once
#include "EnemyBase.h"

class CEnemyRotatingTwoTriangleUp : public CEnemyBase
{
public:
	float m_moveSpeed;
	float m_rotateSpeed;
	float m_moveDirection;
public:
	CEnemyRotatingTwoTriangleUp();
	~CEnemyRotatingTwoTriangleUp();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};