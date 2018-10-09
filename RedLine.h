#pragma once
#include "VFXBase.h"

class CRedLine : public CVFXBase
{
	POINT* m_TargetPolygon;

	float m_Distance;
	float m_InnerRatio;
	float m_OuterRatio;
	CTimer m_Timer;
public:
	CRedLine(Vector pt, int polyAngle, float distance, COLORREF color);
	~CRedLine();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};

