#pragma once
#include "VFXBase.h"

class CRedZoneFX : public CVFXBase
{
	float m_Distance;
	CTimer m_Timer;
public:
	CRedZoneFX(Vector pt, int polyAngle, float distance, COLORREF color);
	~CRedZoneFX();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};

