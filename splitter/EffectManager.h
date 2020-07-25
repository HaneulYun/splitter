#pragma once
#include "VFXBase.h"

class CEffectManager
{
public:
	std::list<CVFXBase*> m_VFX;

public:
	CEffectManager();
	~CEffectManager();

	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render(Matrix mat);
};