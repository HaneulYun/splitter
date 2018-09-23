#include "stdafx.h"
#include "BaseScene.h"
#include "Gdi.h"

CBaseScene::CBaseScene()
{
}

CBaseScene::~CBaseScene()
{
}

void CBaseScene::Render()
{
	
	g_pGdi->StartDraw();
	
	ApiRender(m_matWorld);
	
	g_pGdi->Blt();
	g_pGdi->StopDraw();
}

Matrix CBaseScene::GetMatrix() const
{
	return m_matWorld;
}
RECT CBaseScene::GetRect() const
{
	return m_worldRect;
}