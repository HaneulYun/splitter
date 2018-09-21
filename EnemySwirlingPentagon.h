#pragma once

class CEnemySwirlingPentagon : public CEnemyBase
{
public:
	float m_moveSpeed;
	float m_rotateSpeed;
	float m_moveDirection;

	CEnemyBase* m_pShield[3];
public:
	CEnemySwirlingPentagon();
	~CEnemySwirlingPentagon();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};