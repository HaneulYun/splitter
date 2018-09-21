#pragma once

class CEffectManager
{
public:
	std::deque<CVFXBase*> m_VFX;

public:
	CEffectManager();
	~CEffectManager();

	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render(Matrix mat);
};