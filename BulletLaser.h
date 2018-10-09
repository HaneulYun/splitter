#pragma once
#include "Timer.h"
#include "BulletBase.h"

class CBulletLaser : public CBulletBase
{
	int m_cnt;
	CTimer m_validTime;
public:
	CBulletLaser(float direction, float time);
	~CBulletLaser();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};

