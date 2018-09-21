#include "stdafx.h"

CBaseWindow::CBaseWindow() : m_bIsActive(false)
{
	if (instance == nullptr)
		instance = this;
	//CInputManager::Instance();
}

CBaseWindow::~CBaseWindow()
{
}

bool CBaseWindow::Initialize()
{
	HINSTANCE hInstance = GetModuleHandle(NULL);

	LPCTSTR szTitle = "NIL_GameEngine";
	//	LoadString( hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING );

	//윈도우 클래스 정의/초기화
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = (WNDPROC)MainWndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = NULL;//LoadIcon(hInstance, (LPCTSTR)IDI_ICON1);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szTitle;
	wcex.hIconSm = NULL;//LoadIcon(wcex.hInstance, (LPCTSTR)IDI_ICON1);

	RegisterClassEx(&wcex);

	m_hWnd = CreateWindow(szTitle,
		szTitle,
		WS_BORDER | WS_CAPTION | WS_SYSMENU,
		0, 0, 0, 0,
		NULL,
		NULL,
		hInstance,
		NULL);

	// RECT rtRect; //사각형 구조체

	m_winRect.left = 0;
	m_winRect.top = 0;
	m_winRect.right = 1280;
	m_winRect.bottom = 720;

	//윈도우 형식을 재정의 함수
	AdjustWindowRect(&m_winRect, WS_BORDER | WS_CAPTION | WS_SYSMENU, false);

	//윈도우 위치
	SetWindowPos(m_hWnd, NULL, 200, 100, m_winRect.right - m_winRect.left, m_winRect.bottom - m_winRect.top, SWP_SHOWWINDOW);

	if (!m_hWnd)
	{
		return false;
	}
	m_bIsActive = true;

	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);

	return true;
}

void CBaseWindow::Terminate()
{

}

int CBaseWindow::OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	m_hClientWnd = hWnd;
	return 0;
}
int CBaseWindow::OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
int CBaseWindow::OnSize(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	GetWindowRect(hWnd, &m_winRect);
	m_winSize.cx = m_winRect.right - m_winRect.left;
	m_winSize.cy = m_winRect.bottom - m_winRect.top;
	GetClientRect(hWnd, &m_clientRect);
	m_clientSize.cx = m_clientRect.right - m_clientRect.left;
	m_clientSize.cy = m_clientRect.bottom - m_clientRect.top;
	return 0;
}
int CBaseWindow::OnTimer(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
int CBaseWindow::OnKeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	memcpy(m_OldKeyState, m_CurKeyState, 256);
	m_CurKeyState[wParam] = true;
	return 0;
}
int CBaseWindow::OnKeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	memcpy(m_OldKeyState, m_CurKeyState, 256);
	m_CurKeyState[wParam] = false;
	return 0;
}
int CBaseWindow::OnLButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	m_MouseState.btn[0] = true;
	return 0;
}
int CBaseWindow::OnLButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	m_MouseState.btn[0] = false;
	return 0;
}
int CBaseWindow::OnRButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	m_MouseState.btn[1] = true;
	return 0;
}
int CBaseWindow::OnRButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	m_MouseState.btn[1] = false;
	return 0;
}
int CBaseWindow::OnMButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	m_MouseState.btn[2] = true;
	return 0;
}
int CBaseWindow::OnMButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	m_MouseState.btn[2] = false;
	return 0;
}
int CBaseWindow::OnMouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	m_MouseState.x = LOWORD(lParam);
	m_MouseState.y = HIWORD(lParam);
	return 0;
}
int CBaseWindow::OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	g_pSystem->ChangeProcess(IProcess::eProcessType_Quit);
	return 0;
}

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		return g_pWindow->OnCreate(hWnd, wParam, lParam);
	case WM_COMMAND:
		return g_pWindow->OnCommand(hWnd, wParam, lParam);
	case WM_SIZE:
		return g_pWindow->OnSize(hWnd, wParam, lParam);
	case WM_TIMER:
		return g_pWindow->OnTimer(hWnd, wParam, lParam);
	case WM_KEYDOWN:
		return g_pWindow->OnKeyDown(hWnd, wParam, lParam);
	case WM_KEYUP:
		return g_pWindow->OnKeyUp(hWnd, wParam, lParam);
	case WM_LBUTTONDOWN:
		return g_pWindow->OnLButtonDown(hWnd, wParam, lParam);
	case WM_LBUTTONUP:
		return g_pWindow->OnLButtonUp(hWnd, wParam, lParam);
	case WM_RBUTTONDOWN:
		return g_pWindow->OnRButtonDown(hWnd, wParam, lParam);
	case WM_RBUTTONUP:
		return g_pWindow->OnRButtonUp(hWnd, wParam, lParam);
	case WM_MBUTTONDOWN:
		return g_pWindow->OnMButtonDown(hWnd, wParam, lParam);
	case WM_MBUTTONUP:
		return g_pWindow->OnMButtonUp(hWnd, wParam, lParam);
	case WM_MOUSEMOVE:
		return g_pWindow->OnMouseMove(hWnd, wParam, lParam);
	case WM_DESTROY:
		g_pWindow->OnDestroy(hWnd, wParam, lParam);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}