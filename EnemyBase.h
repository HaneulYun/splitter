#pragma once
#include "BaseObject.h"
#include "SoundManager.h"
#include "TearFX.h"
#include "DestroyFX.h"
#include "Timer.h"

class CEnemyBase : public CBaseObject
{
public:
	FMOD::Channel* m_pChannel;
	float m_Hp;
	int m_AddScore;

	int m_type;

	CTimer m_afterimageTimer;
public:
	CEnemyBase();
	virtual ~CEnemyBase();

	virtual bool Initialize() = 0;
	virtual void Terminate() = 0;
	virtual bool Pulse() = 0;
};