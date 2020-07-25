#pragma once
#include "VFXBase.h"

class CTearFX : public CVFXBase
{
public:
	CTearFX(Vector pt, float distance, int num, COLORREF color);
	~CTearFX();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};