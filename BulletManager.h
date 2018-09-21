#pragma once

class CBulletManager
{
public:
	std::deque<CBulletBase*> m_Bullet;
public:
	CBulletManager();
	~CBulletManager();

	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render(Matrix mat);
};