#include "stdafx.h"

CWndSystem* CWndSystem::instance = nullptr;
CBaseWindow* CBaseWindow::instance = nullptr;
CInputManager* CInputManager::instance = nullptr;
CSoundManager* CSoundManager::instance = nullptr;
CGdi* CGdi::instance = nullptr;

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPreInst, LPSTR lpCmdLine, int nShowCmd)
{
	// splitter for kpu-G-star
	CWndSystem* pSystem = CWndSystem::Instance();

	pSystem->Initialize();
	
	pSystem->Run();
	
	pSystem->Terminate();

	return 0;
}