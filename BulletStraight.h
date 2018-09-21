#pragma once 

class CBulletStraight : public CBulletBase
{
	int cnt;
public:
	CBulletStraight(float direction);
	~CBulletStraight();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;
};

