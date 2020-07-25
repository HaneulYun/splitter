#pragma once
#include "Timer.h"
#include "BaseObject.h"

#include "BulletStraight.h"
#include "BulletReflection.h"
#include "BulletSprinkle.h"
#include "BulletLaser.h"

#include "BulletGuided.h"

class CSupporter : public CBaseObject
{
	DWORD old;
	CTimer m_targetValidTime;
public:
	CSupporter();
	~CSupporter();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};

