#pragma once
#include "IProcess.h"
#define ratio(x,y,w,h) (g_pWindow->m_clientSize.cx*x < mouseX &&  mouseX < g_pWindow->m_clientSize.cx *x+w && g_pWindow->m_clientSize.cy * y < mouseY && mouseY < g_pWindow->m_clientSize.cy * y + h)


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

	Matrix GetMatrix() const override;
	RECT GetRect() const override;
};