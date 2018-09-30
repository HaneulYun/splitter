#pragma once
#include "stdafx.h"
#include "ImageObject.h"

#define g_pInputManager	CInputManager::Instance()

#define g_pKeyCodeScan(vk) ((g_pInputManager->m_OldKeyState[vk])&&(g_pInputManager->m_CurKeyState[vk]))

struct MOUSESTATE
{
	int x, y;
	char btn[4];
};

class CInputManager
{
public:
	char m_OldKeyState[256];
	char m_CurKeyState[256];
	MOUSESTATE m_MouseState;
	POINT m_mousePoint;
	static CInputManager* instance;

	CImageObject* m_cursorImg;
public:
	CInputManager();
	~CInputManager();

	void Initialize();
	void Pulse();
	void Render();

	static CInputManager* Instance()
	{
		if(instance == nullptr)
			instance = new CInputManager;
		return instance;
	}
};

