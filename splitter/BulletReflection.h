#pragma once
#include "BulletBase.h"

class CBulletReflection : public CBulletBase
{
	int m_cnt;
public:
	CBulletReflection(float direction, int hp);
	~CBulletReflection();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};

