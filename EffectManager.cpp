#include "stdafx.h"
#include "EffectManager.h"

CEffectManager::CEffectManager()
{
	Initialize();
}

CEffectManager::~CEffectManager()
{
	Terminate();
}

bool CEffectManager::Initialize()
{
	m_VFX.clear();
	return true;
}
void CEffectManager::Terminate()
{
	for (auto& v : m_VFX)
		delete v;
	m_VFX.clear();
}
bool CEffectManager::Pulse()
{
	for (int i = m_VFX.size() - 1; i >= 0; --i)
		if (m_VFX[i]->Pulse())
		{
			delete m_VFX[i];
			m_VFX.erase(m_VFX.begin() + i);
		}
	return true;
}
void CEffectManager::Render(Matrix mat)
{
	for (auto& v : m_VFX)
		v->Render(mat);
}