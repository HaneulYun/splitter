#pragma once
#include "BaseRender.h"

class CBaseObject : public CBaseRender
{
public:
	CBaseObject();
	virtual ~CBaseObject();

	virtual bool Initialize() = 0;
	virtual void Terminate() = 0;
	virtual bool Pulse() = 0;

	bool hitBox(RECT rt);
	bool hitPolyton(const CBaseObject* obj, Matrix matWorld);
};