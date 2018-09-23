#include "stdafx.h"
#include "WndSystem.h"

#include "IntroScene.h"
#include "MenuScene.h"
#include "EndlessModeScene.h"
#include "Stage01Scene.h"
#include "OptionScene.h"
#include "GameoverScene.h"
#include "NILScene.h"

CWndSystem::CWndSystem()
{
	if (instance == nullptr)
		instance = this;

	m_pCurProcess = NULL;

	m_pSoundManager = NULL;

	m_pChannel = NULL;

	m_abc = 0.5;
}

CWndSystem::~CWndSystem()
{
	Terminate();
}

bool CWndSystem::Initialize()
{
	CBaseWindow::Initialize();
	CTimeManager::Initialize();
	m_pGdi = new CGdi();

	ChangeProcess(IProcess::eProcessType_LoadScene);


	return 0;
}
void CWndSystem::Terminate()
{
	CTimeManager::Terminate();
	if (m_pCurProcess)
	{		
		delete m_pCurProcess;
		m_pCurProcess = NULL;
	}
	CBaseWindow::Terminate();
}

void CWndSystem::Update()
{
	CTimeManager::Pulse();
	CBaseWindow::Pulse();
	if(m_pSoundManager)
		m_pSoundManager->Pulse();
	if (m_pCurProcess) m_pCurProcess->Pulse();
	if (m_pCurProcess) m_pCurProcess->Render();
}

void CWndSystem::ChangeProcess(IProcess::eProcessType eType)
{
	if (m_pCurProcess)
	{
		m_pCurProcess->Terminate();

		delete m_pCurProcess;
		m_pCurProcess = NULL;
	}
	
	switch (eType)
	{
	case IProcess::eProcessType_LoadScene:
		m_pCurProcess = new IntroScene();
		break;

	case IProcess::eProcessType_MenuScene:
		m_pCurProcess = new MenuScene;
		break;

	case IProcess::eProcessType_GameScene:
		m_pCurProcess = new EndlessModeScene();
		break;

	case IProcess::eProcessType_Stage01Scene:
		m_pCurProcess = new Stage01Scene();
		break;

	case IProcess::eProcessType_OptionScene:
		m_pCurProcess = new OptionScene();
		break;

	case IProcess::eProcessType_GameoverScene:
		m_pCurProcess = new GameoverScene();
		break;

	case IProcess::eProcessType_NILScene:
		m_pCurProcess = new NILScene();
		break;
	
	case IProcess::eProcessType_Quit:
		m_bIsActive = false;
		PostMessage(m_hWnd, WM_CLOSE, 0, 0);
		break;
	}
	
	if (m_pCurProcess)
	{
		m_pCurProcess->Initialize();
	}
}

void CWndSystem::KeyboardHandler()
{
}

void CWndSystem::Run()
{
	MSG msg;

	PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&msg, NULL, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
				return;
		}
		else if (m_bIsActive)
			Update();
		else
			WaitMessage();
	}
}
