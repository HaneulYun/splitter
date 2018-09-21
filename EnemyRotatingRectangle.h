#pragma once

class CEnemyRotatingRectangle : public CEnemyBase
{
public:
	float m_moveSpeed;
	float m_rotateSpeed;
	float m_moveDirection;
public:
	CEnemyRotatingRectangle();
	~CEnemyRotatingRectangle();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};
