#pragma once
#include "VFXBase.h"

class CRedZoneFX : public CVFXBase
{
	POINT* m_TargetPolygon;

	float m_Distance;
	float m_InnerRatio;
	float m_OuterRatio;
	CTimer m_Timer;
public:
	CRedZoneFX(Vector pt, int polyAngle, float distance, COLORREF color);
	~CRedZoneFX();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};

