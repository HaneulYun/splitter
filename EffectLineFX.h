#pragma once
#include "VFXBase.h"

class CEffectLineFX : public CVFXBase
{
	POINT* m_TargetPolygon;

	float m_Distance;
	float m_InnerRatio;
	float m_OuterRatio;
	CTimer m_Timer;
public:
	CEffectLineFX(Vector pt, float distance, COLORREF color);
	~CEffectLineFX();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};

