#pragma once
#include "BulletBase.h"

class CBulletbomb : public CBulletBase
{
	int m_cnt;
public:
	CBulletbomb(float direction, int hp);
	~CBulletbomb();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};

