#pragma once
#include "BulletBase.h"

class CBulletBomb : public CBulletBase
{
	int m_cnt;
public:
	CBulletBomb(float direction, float damage);
	~CBulletBomb();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};

