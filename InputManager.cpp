#include "stdafx.h"

CInputManager::CInputManager()
{
	if (instance == nullptr)
		instance = this;
	Initialize();
}

CInputManager::~CInputManager()
{
}

void CInputManager::Initialize()
{
	for (int i = 0; i < 256; ++i)
	{
		m_OldKeyState[i] = 0;
		m_CurKeyState[i] = 0;
	}
	m_MouseState = { 0, };
}

void CInputManager::Pulse()
{
	memcpy(m_OldKeyState, m_CurKeyState, 256);
}