#pragma once
#include "BulletBase.h"

class CBulletSprinkle : public CBulletBase
{
	int cnt;
public:
	CBulletSprinkle(float direction);
	~CBulletSprinkle();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};

