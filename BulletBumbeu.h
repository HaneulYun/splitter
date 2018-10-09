#pragma once
#include "BulletBase.h"

class BulletBumbeu : public CBulletBase
{
	int m_cnt;
public:
	BulletBumbeu(float direction, int hp);
	~BulletBumbeu();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};

