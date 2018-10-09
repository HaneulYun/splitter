#pragma once
#include "BulletBase.h"

class Bulletbomb : public CBulletBase
{
	int m_cnt;
public:
	Bulletbomb(float direction, int hp);
	~Bulletbomb();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};

