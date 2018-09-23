#pragma once
#include "BaseObject.h"

class CBulletBase : public CBaseObject
{
public:
	int m_activeState;

	float m_direction;
	float m_speed;

	FMOD::Channel* m_pChannel;
public:
	CBulletBase();
	virtual ~CBulletBase();

	virtual bool Initialize() = 0;
	virtual void Terminate() = 0;
	virtual bool Pulse() = 0;
};

