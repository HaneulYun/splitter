#pragma once
#include "BaseObject.h"
#include "Timer.h"
#include "BulletStraight.h"
#include "BulletReflection.h"

class CPlayer : public CBaseObject
{
	DWORD old;

	bool m_WhirlWind;
	float m_rotateWhirlWind;
	DWORD m_OldBulletTime;
	CTimer m_TimerWhirlWind;

public:
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

