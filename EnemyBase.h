#pragma once

class CEnemyBase : public CBaseObject
{
public:
	FMOD::Channel* m_pChannel;
	int m_Hp;
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