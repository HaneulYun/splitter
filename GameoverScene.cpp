#include "stdafx.h"
#include "GameoverScene.h"
#include "WndSystem.h"

#define WIDTH_NORMALIZE(x) (-m_worldRect.right/2+m_worldRect.right*(x/1280.f))
#define HEIGHT_NORMALIZE(y) (-m_worldRect.bottom/2+m_worldRect.bottom*(y/720.f))

GameoverScene::GameoverScene()
{
	Initialize();
}

GameoverScene::~GameoverScene()
{
	Terminate();
}

bool GameoverScene::Initialize()
{
	Matrix mat;
	m_matWorld.Identity();
	m_matWorld.m11 = 0.35 *  cos(0.0);
	m_matWorld.m12 = 0.35 *  sin(0.0);
	m_matWorld.m21 = 0.35 * -sin(0.0);
	m_matWorld.m22 = 0.35 *  cos(0.0);
	m_matWorld.m31 = g_pWindow->m_clientSize.cx / 2;
	m_matWorld.m32 = g_pWindow->m_clientSize.cy / 2;
	m_matOrigin = m_matWorld;

	m_worldRect =
	{
		-(LONG)(g_pWindow->m_clientSize.cx / 2 / 0.35),
		-(LONG)(g_pWindow->m_clientSize.cy / 2 / 0.35),
		+(LONG)(g_pWindow->m_clientSize.cx / 2 / 0.35),
		+(LONG)(g_pWindow->m_clientSize.cy / 2 / 0.35)
	};

	m_TextFPS = new CText();

	m_TextFPS->FontInitialize(20, "game over Regular", 30, 0);
	m_TextFPS->ObjectInitialize(WIDTH_NORMALIZE(10), HEIGHT_NORMALIZE(10), RGB(0xff, 0xff, 0xff), RGB(0x00, 0x00, 0x00), 1);

	m_Gameover = new CText();
	m_Gameover->FontInitialize(20, "Pixel", 150, 80);
	m_Gameover->ObjectInitialize(WIDTH_NORMALIZE(280), HEIGHT_NORMALIZE(50), RGB(0xff, 0xff, 0xff), RGB(0x00, 0x00, 0x00), 1);

	m_Score = new CText();
	m_Score->FontInitialize(20, "Pixel", 50, 30);
	m_Score->ObjectInitialize(WIDTH_NORMALIZE(450), HEIGHT_NORMALIZE(300), RGB(0xff, 0xff, 0xff), RGB(0x00, 0x00, 0x00), 1);

	m_BestScore = new CText();
	m_BestScore->FontInitialize(20, "Pixel", 40, 25);
	m_BestScore->ObjectInitialize(WIDTH_NORMALIZE(450), HEIGHT_NORMALIZE(400), RGB(0xff, 0xff, 0xff), RGB(0x00, 0x00, 0x00), 1);

	m_Exit = new CText();
	m_Exit->FontInitialize(20, "Pixel", 40, 25);
	m_Exit->ObjectInitialize(WIDTH_NORMALIZE(500), HEIGHT_NORMALIZE(550), RGB(0x99, 0x99, 0x99), RGB(0x00, 0x00, 0x00), 1);

	m_Retry = new CText();
	m_Retry->FontInitialize(20, "Pixel", 40, 25);
	m_Retry->ObjectInitialize(WIDTH_NORMALIZE(680), HEIGHT_NORMALIZE(550), RGB(0x99, 0x99, 0x99), RGB(0x00, 0x00, 0x00), 1);
	return true;
}

void GameoverScene::Terminate()
{
	if (m_TextFPS)
	{
		m_TextFPS->Terminate();
		m_TextFPS = nullptr;
	}
	if (m_Gameover)
	{
		m_Gameover->Terminate();
		m_Gameover = nullptr;
	}
	if (m_Score) {
		m_Score->Terminate();
		m_Score = nullptr;
	}
	if (m_BestScore) {
		m_BestScore->Terminate();
		m_BestScore = nullptr;
	}
	if (m_Exit) {
		m_Exit->Terminate();
		m_Exit = nullptr;
	}
	if (m_Retry) {
		m_Retry->Terminate();
		m_Retry = nullptr;
	}
}

bool GameoverScene::Pulse()
{
	char str[30];
	//int maxScore = 123;

	sprintf(str, "FPS : %.2f", g_pSystem->GetFPS());
	m_TextFPS->Pulse(str);
	sprintf(str, "GAME OVER");
	m_Gameover->Pulse(str);
	sprintf(str, "SCORE:         %d", g_pSystem->m_Score);
	m_Score->Pulse(str);
	sprintf(str, "BEST SCORE:    %d", g_pSystem->m_Score);
	m_BestScore->Pulse(str);
	sprintf(str, "EXIT");
	m_Exit->Pulse(str);
	sprintf(str, "RETRY");
	m_Retry->Pulse(str);

	mouseX = g_pInputManager->m_MouseState.x;
	mouseY = g_pInputManager->m_MouseState.y;

	if (ratio(26 / 68, 30/ 40, 100, 100)) {
		m_Exit->m_Color = RGB(0xff, 0xff, 0xff);
		if (g_pInputManager->m_MouseState.btn[0])
			g_pSystem->ChangeProcess(eProcessType_MenuScene);
	}
	else if (ratio(36 / 68, 30 / 40, 130, 100)) {
		m_Retry->m_Color = RGB(0xff, 0xff, 0xff);
		if (g_pInputManager->m_MouseState.btn[0])
			g_pSystem->ChangeProcess(eProcessType_GameScene);
	}
	else if ((g_pKeyCodeScan('m') || g_pKeyCodeScan('M')))
		g_pSystem->ChangeProcess(eProcessType_MenuScene);
	else {
		m_Exit->m_Color = RGB(0x99, 0x99, 0x99);
		m_Retry->m_Color = RGB(0x99, 0x99, 0x99);
	}
	return true;
}

void GameoverScene::ApiRender(Matrix mat)
{
	m_TextFPS->Render(mat);
	m_Gameover->Render(mat);
	m_Score->Render(mat);
	m_BestScore->Render(mat);
	m_Exit->Render(mat);
	m_Retry->Render(mat);
}