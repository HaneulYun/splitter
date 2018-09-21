#pragma once
class CBaseScene : public IProcess
{
public:
	Matrix m_matWorld;
	RECT m_worldRect;

	FMOD::Channel* m_pChannel;
public:
	CBaseScene();
	~CBaseScene();

	virtual bool Initialize() = 0;
	virtual void Terminate() = 0;
	virtual bool Pulse() = 0;
	void Render();
	virtual void ApiRender(Matrix mat) = 0;

	Matrix GetMatrix() const override
	{
		return m_matWorld;
	}
	RECT GetRect() const override
	{
		return m_worldRect;
	}
};