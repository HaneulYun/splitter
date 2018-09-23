#pragma once

#include "InputManager.h"

#define g_pWindow	CBaseWindow::Instance()

class CBaseWindow : public CInputManager
{
protected:
	BOOL	m_bIsActive;
	static CBaseWindow* instance;

public:
	HWND	m_hWnd;
	HWND	m_hClientWnd;
	RECT	m_winRect, m_clientRect;
	SIZE	m_winSize, m_clientSize;

	BOOL	m_isFullScreen;

	CBaseWindow();
	virtual ~CBaseWindow();

	bool Initialize();
	void Terminate();

	int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam);
	int OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam);
	int OnSize(HWND hWnd, WPARAM wParam, LPARAM lParam);
	int OnTimer(HWND hWnd, WPARAM wParam, LPARAM lParam);
	int OnKeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
	int OnKeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
	//int OnKeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
	//int OnKeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
	//int OnKeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
	int OnLButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
	int OnLButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
	int OnRButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
	int OnRButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
	int OnMButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
	int OnMButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
	int OnMouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam);
	int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam);

	__inline HWND GetHandle() const
	{
		return m_hWnd;
	}

	static CBaseWindow* Instance()
	{
		if(instance == nullptr)
			instance = new CBaseWindow();
		return instance;
	}
};

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);