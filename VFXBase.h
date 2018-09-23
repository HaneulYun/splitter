#pragma once
#include "BaseObject.h"
#include "Timer.h"

class CVFXBase : public CBaseObject
{
public:
	CVFXBase();
	virtual ~CVFXBase();

	virtual bool Initialize() = 0;
	virtual void Terminate() = 0;
	virtual bool Pulse() = 0;
};