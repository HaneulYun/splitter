#pragma once
#include "BaseObject.h"
#include "Timer.h"
#include "BulletStraight.h"
#include "BulletReflection.h"
#include "BulletSprinkle.h"
#include "BulletLaser.h"

#include "BulletGuided.h"

#include "CSupporter.h"

class CPlayer : public CBaseObject
{
	DWORD old;

	bool m_WhirlWind;
	float m_rotateWhirlWind;
	DWORD m_OldBulletTime;
	CTimer m_TimerWhirlWind;
	float m_normalSupporterDist;
	float m_normalSupporterPos;

public:
	CSupporter m_supporter[5];

	int m_gunType;
	int m_gunLevel;

	std::deque<CBulletStraight*> m_BulletWhirlWind;
public:
	CPlayer();
	~CPlayer();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};

