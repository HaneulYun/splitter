#pragma once
#include "BulletBase.h"

class CBulletLaser : public CBulletBase
{
	int m_cnt;
public:
	CBulletLaser(float direction, int hp);
	~CBulletLaser();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};

