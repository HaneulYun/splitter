#include "stdafx.h"

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