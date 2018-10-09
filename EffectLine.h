#pragma once
#include "VFXBase.h"

class CEffectLine : public CVFXBase
{
	POINT* m_TargetPolygon;

	float m_Distance;
	float m_InnerRatio;
	float m_OuterRatio;
	CTimer m_Timer;
public:
	CEffectLine(Vector pt, int polyAngle, float distance, COLORREF color);
	~CEffectLine();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};

