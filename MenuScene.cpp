#include "stdafx.h"
#include "MenuScene.h"
#include "WndSystem.h"


#define WIDTH_NORMALIZE(x) (-m_worldRect.right/2.f + m_worldRect.right*((x)/1280.f))
#define HEIGHT_NORMALIZE(y) (-m_worldRect.bottom/2+m_worldRect.bottom*((y)/720.f))


MenuScene::MenuScene()
{
	Initialize();
	bool isPlaying;
	g_pSoundManager->m_pChannel->isPlaying(&isPlaying);
	if (!isPlaying)
		g_pSoundManager->Pulse(g_pSoundManager->m_pChannel, 0);
}

MenuScene::~MenuScene()
{
	Terminate();
}

bool MenuScene::Initialize()
{
	g_pInputManager->m_MouseState.x;
	g_pInputManager->m_MouseState.y;
	//g_pWindow->m_clientRect
	m_matWorld.Identity();
	m_matWorld.m11 = (float)g_pWindow->m_clientSize.cx / g_pWindow->m_winNormalRect.right * 0.35 *  cos(0.0);
	m_matWorld.m12 = (float)g_pWindow->m_clientSize.cx / g_pWindow->m_winNormalRect.right * 0.35 *  sin(0.0);
	m_matWorld.m21 = (float)g_pWindow->m_clientSize.cx / g_pWindow->m_winNormalRect.right * 0.35 * -sin(0.0);
	m_matWorld.m22 = (float)g_pWindow->m_clientSize.cx / g_pWindow->m_winNormalRect.right * 0.35 *  cos(0.0);
	m_matWorld.m31 = (float)g_pWindow->m_clientSize.cx / 2;
	m_matWorld.m32 = (float)g_pWindow->m_clientSize.cy / 2;
	m_matOrigin = m_matWorld;

	m_worldRect =
	{
		-(LONG)(m_matWorld.m31 / m_matWorld.m11),
		-(LONG)(m_matWorld.m32 / m_matWorld.m22),
		+(LONG)(m_matWorld.m31 / m_matWorld.m11),
		+(LONG)(m_matWorld.m32 / m_matWorld.m22)
	};
	
	m_TextSPLITTER = new CText;
	m_TextSPLITTER->FontInitialize(20, "Delta Universe-Regular", 150, 0);
	m_TextSPLITTER->ObjectInitialize(WIDTH_NORMALIZE(500), HEIGHT_NORMALIZE(100), RGB(0xff, 0xff, 0xff), RGB(0x00, 0x00, 0x00), 1);

	m_TextFPS = new CText();
	m_TextFPS->FontInitialize(20, "Delta Universe-Regular", 50, 0);
	m_TextFPS->ObjectInitialize(WIDTH_NORMALIZE(10), HEIGHT_NORMALIZE(10), RGB(0xff, 0xff, 0xff), RGB(0x00, 0x00, 0x00), 1);

	m_TextEndless = new CText;
	m_TextEndless->FontInitialize(20, "Delta Universe-Regular", 90, 0);
	m_TextEndless->ObjectInitialize(WIDTH_NORMALIZE(300), HEIGHT_NORMALIZE(280), RGB(0x88, 0x88, 0x88), RGB(0x00, 0x00, 0x00), 1);

	m_TextStage1 = new CText;
	m_TextStage1->FontInitialize(20, "Delta Universe-Regular", 90, 0);
	m_TextStage1->ObjectInitialize(WIDTH_NORMALIZE(330), HEIGHT_NORMALIZE(380), RGB(0x88, 0x88, 0x88), RGB(0x00, 0x00, 0x00), 1);

	m_TextCrazy = new CText;
	m_TextCrazy->FontInitialize(20, "Delta Universe-Regular", 90, 0);
	m_TextCrazy->ObjectInitialize(WIDTH_NORMALIZE(300), HEIGHT_NORMALIZE(480), RGB(0x88, 0x88, 0x88), RGB(0x00, 0x00, 0x00), 1);

	m_TextExit = new CText;
	m_TextExit->FontInitialize(20, "Delta Universe-Regular", 90, 30);
	m_TextExit->ObjectInitialize(WIDTH_NORMALIZE(780), HEIGHT_NORMALIZE(380), RGB(0x88, 0x88, 0x88), RGB(0x00, 0x00, 0x00), 1);

	m_Option = new CText;
	m_Option->FontInitialize(20, "Delta Universe-Regular", 90, 30);
	m_Option->ObjectInitialize(WIDTH_NORMALIZE(750), HEIGHT_NORMALIZE(280), RGB(0x88, 0x88, 0x88), RGB(0x00, 0x00, 0x00), 1);
	
	m_Nil.Initialize("resources/image/ÇÏ´Ã1.jpg", -800, -650, 1.5f);
	m_JJang.Initialize("resources/image/¼öÇö1.jpg", 700, -600, 1.5f);
	return true;
}

void MenuScene::Terminate()
{
	m_Nil.Terminate();
	m_JJang.Terminate();
}

bool MenuScene::Pulse()
{
	char str[20];
	sprintf(str, "FPS : %.2f", g_pSystem->GetFPS());
	m_TextFPS->Pulse(str);
	sprintf(str, "SPLITTER");
	m_TextSPLITTER->Pulse(str);

	sprintf(str, "Endless Mode");
	m_TextEndless->Pulse(str);
	sprintf(str, "Stage 1");
	m_TextStage1->Pulse(str);
	sprintf(str, "Crazy Mode");
	m_TextCrazy->Pulse(str);
	sprintf(str, "EXIT");
	m_TextExit->Pulse(str);
	sprintf(str, "OPTION");
	m_Option->Pulse(str);

	mouseX = g_pInputManager->m_MouseState.x;
	mouseY = g_pInputManager->m_MouseState.y;

	mousePt = g_pInputManager->m_mousePoint;
	POINT mousePoint = g_pInputManager->m_mousePoint;
	RECT mouseRect{ mousePoint.x, mousePoint.y, mousePoint.x, mousePoint.y};

	
	if(ratioNil(300, 250, 240,165)){
	//if (ratio(1/4,2/5,200,50)) {
	//if (m_TextEndless->hitBox(mouseRect)) {
		m_TextEndless->m_Point.x = WIDTH_NORMALIZE(270);
		m_TextEndless->m_Point.y = HEIGHT_NORMALIZE(250);
		m_TextEndless->m_Color = RGB(0xff, 0xff, 0xff);
		sprintf(str, "¢ºEndless Mode");
		m_TextEndless->Pulse(str);
		if (g_pInputManager->m_MouseState.btn[0]) {
			g_pSoundManager->ChannelStop(g_pSoundManager->m_pChannel);
			g_pSystem->ChangeProcess(eProcessType_GameScene);
			return true;
		}
	}
	else if (ratio(17 / 64, 11/20, 125, 70)) {
		m_TextStage1->m_Point.x = WIDTH_NORMALIZE(300);
		m_TextStage1->m_Color = RGB(0xff, 0xff, 0xff);
		sprintf(str, "¢ºStage 1");
		m_TextStage1->Pulse(str);
		if (g_pInputManager->m_MouseState.btn[0]) {
			g_pSoundManager->ChannelStop(g_pSoundManager->m_pChannel);
			g_pSystem->ChangeProcess(eProcessType_Stage01Scene);
			return true;
		}
	}
	else if (ratio(17 / 64, 27 / 40, 240, 100))
	{
		m_TextCrazy->m_Point.x = WIDTH_NORMALIZE(330);
		m_TextCrazy->m_Color = RGB(0xff, 0xff, 0xff);
		sprintf(str, "¢ºCrazy Mode");
		m_TextCrazy->Pulse(str);
			if (g_pInputManager->m_MouseState.btn[0]) {
				g_pSoundManager->ChannelStop(g_pSoundManager->m_pChannel);
				g_pSystem->ChangeProcess(eProcessType_CrazyScene);
				return true;
			}
	}
	else if (ratio(3 / 5, 15/28, 100, 75)) {
		m_TextExit->m_Point.x = WIDTH_NORMALIZE(730);
		m_TextExit->m_Color = RGB(0xff, 0xff, 0xff);
		sprintf(str, "¢ºEXIT");
		m_TextExit->Pulse(str);
		if (g_pInputManager->m_MouseState.btn[0]) {
			g_pSystem->ChangeProcess(eProcessType_Quit);
			return true;
		}
	}
	//else if (250 < mouseX && mouseX < 450 && 0 < mouseY && mouseY < 230) {
	//	if (g_pInputManager->m_MouseState.btn[0]) {
	//		g_pSystem->ChangeProcess(eProcessType_NILScene);
	//		return true;
	//	}
	//}
	else if (ratio(3 / 5, 11 / 28, 100, 75))
	{
		m_Option->m_Point.x = WIDTH_NORMALIZE(720);
		m_Option->m_Color = RGB(0xff, 0xff, 0xff);
		sprintf(str, "¢ºOPTION");
		m_Option->Pulse(str);
		if (g_pInputManager->m_MouseState.btn[0]) {
			g_pSystem->ChangeProcess(eProcessType_OptionScene);
			return true;
		}
		//m_Option->ObjectInitialize(750, 280, RGB(0x88, 0x88, 0x88), RGB(0x00, 0x00, 0x00), 1);
	}
	else
	{
		m_TextEndless->m_Point.x = WIDTH_NORMALIZE(330);
		m_TextEndless->m_Color = RGB(0x88, 0x88, 0x88);
		sprintf(str, "Endless Mode");
		m_TextEndless->Pulse(str);
		m_TextStage1->m_Point.x = WIDTH_NORMALIZE(330);
		m_TextStage1->m_Color = RGB(0x88, 0x88, 0x88);
		sprintf(str, "Stage 1");
		m_TextStage1->Pulse(str);
		m_TextCrazy->m_Point.x = WIDTH_NORMALIZE(330);
		m_TextCrazy->m_Color = RGB(0x88, 0x88, 0x88);
		sprintf(str, "Crazy Mode");
		m_TextCrazy->Pulse(str);
		m_TextExit->m_Point.x = WIDTH_NORMALIZE(780);
		m_TextExit->m_Color = RGB(0x88, 0x88, 0x88);
		sprintf(str, "EXIT");
		m_TextExit->Pulse(str);
		m_Option->m_Point.x = WIDTH_NORMALIZE(750);
		m_Option->m_Color = RGB(0x88, 0x88, 0x88);
		sprintf(str, "OPTION");
		m_Option->Pulse(str);
	}

	if ((g_pKeyCodeScan('e') || g_pKeyCodeScan('E')))
		g_pSystem->ChangeProcess(eProcessType_GameScene);
	if ((g_pKeyCodeScan('1')))
		g_pSystem->ChangeProcess(eProcessType_Stage01Scene);
	if ((g_pKeyCodeScan('g') || g_pKeyCodeScan('G')))
		g_pSystem->ChangeProcess(eProcessType_GameoverScene);


	return true;
}

void MenuScene::ApiRender(Matrix mat)
{
	m_TextFPS->Render(mat);
	m_TextSPLITTER->Render(mat);
	m_TextEndless->Render(mat);
	m_TextStage1->Render(mat);
	m_TextCrazy->Render(mat);
	m_TextExit->Render(mat);
	m_Option->Render(mat);

	m_Nil.Render(mat);
	m_JJang.Render(mat);
}
