#include "stdafx.h"
#include "OptionScene.h"
#include "WndSystem.h"
#include "SoundManager.h"

OptionScene::OptionScene()
{
	Initialize();
}


OptionScene::~OptionScene()
{
	Terminate();
}

bool OptionScene::Initialize()
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

	m_SouudFX = new CText;
	m_SouudFX->FontInitialize(30, "Delta Universe-Regular", 50, 0);
	m_SouudFX->ObjectInitialize(100, 80, RGB(0xaa, 0xaa, 0xaa), RGB(0x00, 0x00, 0x00), 1);

	m_SoundFXbar.Initialize(-850, -500, RGB(0x77, 0x77, 0x77), CButtonObject::eButtonType_scroll);
	//m_soundFXbutton.Initialize(-850, -500, RGB(0xff, 0xff, 0xff), CButtonObject::eButtonType_button);

	float r;
	g_pSoundManager->m_effectSoundChannel->getVolume(&r);
	m_barSound = new CText;
	m_barSound->FontInitialize(30, "Delta Universe-Regular", 90, 0);
	m_barSound->ObjectInitialize(80 + 480*r, 125, RGB(0xff, 0xff, 0xff), RGB(0x00, 0x00, 0x00), 1);

	m_Music = new CText;
	m_Music->FontInitialize(30, "Delta Universe-Regular", 50, 0);
	m_Music->ObjectInitialize(100, 270, RGB(0xaa, 0xaa, 0xaa), RGB(0x00, 0x00, 0x00), 1);

	g_pSoundManager->m_BGMChannel->getVolume(&r);
	m_barMusic = new CText;
	m_barMusic->FontInitialize(30, "Delta Universe-Regular", 90, 0);
	m_barMusic->ObjectInitialize(80 + 480 * r, 300, RGB(0xff, 0xff, 0xff), RGB(0x00, 0x00, 0x00), 1);

	m_MusicBar.Initialize(-850, 0, RGB(0x77, 0x77, 0x77), CButtonObject::eButtonType_scroll);

	m_ScreenShake = new CText;
	m_ScreenShake->FontInitialize(30, "Delta Universe-Regular", 50, 0);
	m_ScreenShake->ObjectInitialize(100, 460, RGB(0xaa, 0xaa, 0xaa), RGB(0x00, 0x00, 0x00), 1);

	m_ScreenShakeBar.Initialize(-850, 600, RGB(0x77, 0x77, 0x77), CButtonObject::eButtonType_scroll);
	//m_ScreenShakeButton.Initialize(-850, 600, RGB(0xff, 0xff, 0xff), CButtonObject::eButtonType_button);

	r = g_pSystem->m_abc;
	m_barScreen = new CText;
	m_barScreen->FontInitialize(30, "Delta Universe-Regular", 90, 0);
	m_barScreen->ObjectInitialize(80 + 480 * r, 510, RGB(0xff, 0xff, 0xff), RGB(0x00, 0x00, 0x00), 1);

	m_FullScreen = new CText;
	m_FullScreen->FontInitialize(30, "Delta Universe-Regular", 50, 0);
	m_FullScreen->ObjectInitialize(800, 200, RGB(0xaa, 0xaa, 0xaa), RGB(0x00, 0x00, 0x00), 1);

	m_ON = new CText;
	m_ON->FontInitialize(30, "Delta Universe-Regular", 50, 0);
	m_ON->ObjectInitialize(830, 300, RGB(0xaa, 0xaa, 0xaa), RGB(0x00, 0x00, 0x00), 1);

	m_OFF = new CText;
	m_OFF->FontInitialize(30, "Delta Universe-Regular", 50, 0);
	m_OFF->ObjectInitialize(950, 300, RGB(247, 255, 83), RGB(0x00, 0x00, 0x00), 1);

	m_Exit = new CText;
	m_Exit->FontInitialize(30, "Delta Universe-Regular", 120, 30);
	m_Exit->ObjectInitialize(880, 420, RGB(0x88, 0x88, 0x88), RGB(0x00, 0x00, 0x00), 1);
	return true;
}

void OptionScene::Terminate()
{

}

bool OptionScene::Pulse()
{
	mouseX = g_pInputManager->m_MouseState.x;
	mouseY = g_pInputManager->m_MouseState.y;


	if (830 < mouseX && mouseX < 880 && 300 < mouseY && mouseY < 350) {
		m_ON->FontInitialize(30, "Delta Universe-Regular", 50, 0, 1);
		if (!g_pWindow->m_isFullScreen)
			if (g_pInputManager->m_MouseState.btn[0])
				g_pWindow->m_isFullScreen = true;
	}
	else if (950 < mouseX && mouseX < 1020 && 300 < mouseY && mouseY < 350) {
		m_OFF->FontInitialize(30, "Delta Universe-Regular", 50, 0, 1);
		if (g_pWindow->m_isFullScreen)
			if (g_pInputManager->m_MouseState.btn[0]) {
				g_pWindow->m_isFullScreen = false;
				return true;
			}
	}
	else if (880 < mouseX && mouseX < 990 && 420 < mouseY && mouseY < 540) {
		m_Exit->FontInitialize(30, "Delta Universe-Regular", 120, 30, 1);
		if (g_pInputManager->m_MouseState.btn[0]) {
			g_pSystem->ChangeProcess(eProcessType_MenuScene);
			return true;
		}
	}
	else if (m_barMusic->m_Point.x - 30 < mouseX && mouseX < m_barMusic->m_Point.x + 60
		&& m_barMusic->m_Point.y + 50 < mouseY && mouseY < m_barMusic->m_Point.y + 100) {
		m_barMusic->m_Color = RGB(247, 255, 83);
		if (g_pInputManager->m_MouseState.btn[0]) {
			m_barMusic->m_Point.x = g_pInputManager->m_MouseState.x - 25; // mouseX;
			if (m_barMusic->m_Point.x > 560)
				m_barMusic->m_Point.x = 560;
			if (m_barMusic->m_Point.x < 80)
				m_barMusic->m_Point.x = 80;
		}
	}
	else if (m_barSound->m_Point.x - 30 < mouseX && mouseX < m_barSound->m_Point.x + 60
		&& m_barSound->m_Point.y + 50 < mouseY && mouseY < m_barSound->m_Point.y + 100)
	{
		m_barSound->m_Color = RGB(247, 255, 83);
		if (g_pInputManager->m_MouseState.btn[0]) {
			m_barSound->m_Point.x = g_pInputManager->m_MouseState.x - 25; // mouseX;
			if (m_barSound->m_Point.x > 560)
				m_barSound->m_Point.x = 560;
			if (m_barSound->m_Point.x < 80)
				m_barSound->m_Point.x = 80;
		}
	}
	else if (m_barScreen->m_Point.x - 30 < mouseX && mouseX < m_barScreen->m_Point.x + 60
		&& m_barScreen->m_Point.y + 50 < mouseY && mouseY < m_barScreen->m_Point.y + 100)
	{
		m_barScreen->m_Color = RGB(247, 255, 83);
		if (g_pInputManager->m_MouseState.btn[0]) {
			m_barScreen->m_Point.x = g_pInputManager->m_MouseState.x - 25; // mouseX;
			if (m_barScreen->m_Point.x > 560)
				m_barScreen->m_Point.x = 560;
			if (m_barScreen->m_Point.x < 80)
				m_barScreen->m_Point.x = 80;
		}
	}
	else {
		m_ON->FontInitialize(30, "Delta Universe-Regular", 50, 0, 0);
		m_OFF->FontInitialize(30, "Delta Universe-Regular", 50, 0, 0);
		m_Exit->FontInitialize(30, "Delta Universe-Regular", 120, 30, 0);

		m_barMusic->m_Color = RGB(255, 255, 255);
		m_barScreen->m_Color = RGB(255, 255, 255);
		m_barSound->m_Color = RGB(255, 255, 255);

	}

	if (g_pWindow->m_isFullScreen) {
		m_ON->m_Color = RGB(247, 255, 83);
	}
	else {
		m_OFF->m_Color = RGB(247, 255, 83);
	}

	g_pSoundManager->m_effectSoundChannel->setVolume(1.0 / 480 * (m_barSound->m_Point.x - 80));
	g_pSoundManager->m_BGMChannel->setVolume(1.0 / 480 * (m_barMusic->m_Point.x - 80));
	g_pSystem->m_abc = 1.0 / 480 * (m_barSound->m_Point.x - 80);

	char str[30];

	sprintf(str, "S O U N D   F X");
	m_SouudFX->Pulse(str);
	sprintf(str, "M U S I C");
	m_Music->Pulse(str);
	sprintf(str, "S C R E E N   S H A K E");
	m_ScreenShake->Pulse(str);
	sprintf(str, "F U L L   S C R E E N");
	m_FullScreen->Pulse(str);
	sprintf(str, "O N");
	m_ON->Pulse(str);
	sprintf(str, "O F F");
	m_OFF->Pulse(str);
	sprintf(str, "EXIT");
	m_Exit->Pulse(str);
	sprintf(str, "бс");
	m_barMusic->Pulse(str);
	sprintf(str, "бс");
	m_barSound->Pulse(str);
	sprintf(str, "бс");
	m_barScreen->Pulse(str);

	if ((g_pKeyCodeScan('m') || g_pKeyCodeScan('M')))
		g_pSystem->ChangeProcess(eProcessType_MenuScene);
	return true;
}

void OptionScene::ApiRender(Matrix mat)
{
	m_SouudFX->Render(mat);
	m_SoundFXbar.Render(mat);
	//m_soundFXbutton.Render(mat);
	m_Music->Render(mat);
	m_MusicBar.Render(mat);
	m_ScreenShake->Render(mat);
	m_ScreenShakeBar.Render(mat);
	//m_ScreenShakeButton.Render(mat);
	m_FullScreen->Render(mat);
	m_ON->Render(mat);
	m_OFF->Render(mat);
	m_Exit->Render(mat);
	m_barMusic->Render(mat);
	m_barScreen->Render(mat);
	m_barSound->Render(mat);
}