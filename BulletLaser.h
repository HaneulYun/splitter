#pragma once
#include "BulletBase.h"

class BulletLaser : public CBulletBase
{
	int m_cnt;
public:
	BulletLaser(float direction, int hp);
	~BulletLaser();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};

