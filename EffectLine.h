#pragma once
#include "VFXBase.h"

class CEffectLine : public CVFXBase
{

public:
	CEffectLine(Vector pt, COLORREF color, float distance, float direction);
	~CEffectLine();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};

