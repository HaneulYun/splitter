#pragma once
#include "VFXBase.h"

class CAfterimageFX : public CVFXBase
{
	POINT* m_TargetPolygon;
	COLORREF m_oriColor;
	CTimer m_Timer;
	float m_delay;
public:
	CAfterimageFX(CBaseObject* obj, COLORREF color, float delay);
	~CAfterimageFX();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};