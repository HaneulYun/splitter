#include "stdafx.h"
#include "TearFX.h"
#include "TearElement.h"
#include "GameSceneBase.h"

CTearFX::CTearFX(Vector pt, float distance, int num, COLORREF color)
{
	for(int i = 0; i < num; ++i)
		g_pGameScene->m_EffectManager->m_VFX.push_back(new CTearElement(pt, 8, distance, color));
}

CTearFX::~CTearFX()
{
}

bool CTearFX::Initialize()
{
	return true;
}
void CTearFX::Terminate()
{

}
bool CTearFX::Pulse()
{
	return true;
}