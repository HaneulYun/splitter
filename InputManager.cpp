#include "stdafx.h"
#include "WndSystem.h"

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
	m_mousePoint = { 0, };
}

void CInputManager::Pulse()
{
	memcpy(m_OldKeyState, m_CurKeyState, 256);

	m_mousePoint.x = g_pInputManager->m_MouseState.x - g_pWindow->m_clientSize.cx / 2;
	m_mousePoint.y = g_pInputManager->m_MouseState.y - g_pWindow->m_clientSize.cy / 2;

	m_mousePoint = g_pSystem->m_pCurProcess->GetMatrix().Translate(m_mousePoint);

	m_mousePoint.x -= g_pWindow->m_clientSize.cx / 2;
	m_mousePoint.y -= g_pWindow->m_clientSize.cy / 2;
}