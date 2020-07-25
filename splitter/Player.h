#pragma once
#include "BaseObject.h"
#include "Timer.h"
#include "BulletStraight.h"
#include "BulletReflection.h"
#include "BulletSprinkle.h"
#include "BulletLaser.h"
#include "BulletBomb.h"
#include "BulletGuided.h"

#include "CSupporter.h"

class CPlayer : public CBaseObject
{
	DWORD old;

	bool m_WhirlWind;
	float m_rotateWhirlWind;
	DWORD m_OldBulletTime;
	CTimer m_TimerWhirlWind;

	CTimer m_TimerSuperSupporter;
	float m_normalSupporterDist;
	float m_normalSupporterPos;

	bool m_RedZone;
	CTimer m_TimerRedZone;

public:
	bool m_SuperSupporter;
	CSupporter m_supporter[5];

	int m_gunType;
	int m_gunLevel;

	std::list<CBulletStraight*> m_BulletWhirlWind;
public:
	CPlayer();
	~CPlayer();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};

