#pragma once
#include "EnemyBase.h"

class CEnemyRotatingTriangleShield : public CEnemyBase
{
public:
	float m_moveSpeed;
	float m_rotateSpeed;
	float m_moveDirection;
public:
	CEnemyRotatingTriangleShield();
	~CEnemyRotatingTriangleShield();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};