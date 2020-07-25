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
	for (auto iter = std::begin(m_VFX); iter != std::end(m_VFX);)
	{
		auto& vfx = *iter;
		if (!vfx->Pulse())
		{
			++iter;
			continue;
		}

		delete vfx;
		iter = m_VFX.erase(iter);
	}

	return true;
}
void CEffectManager::Render(Matrix mat)
{
	for (auto& v : m_VFX)
		v->Render(mat);
}