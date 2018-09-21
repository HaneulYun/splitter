#pragma once

class CShellFX : public CVFXBase
{
	POINT* m_TargetPolygon;

	float m_moveSpeed;
	float m_rotateSpeed;
	float m_moveDirection;

	CTimer m_Timer;
public:
	CShellFX(Vector pt, COLORREF color, float distance, float direction);
	~CShellFX();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};