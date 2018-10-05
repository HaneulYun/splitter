#pragma once
#include "BaseScene.h"
#include "Text.h"
#include "ButtonObject.h"
#include "Timer.h"

class OptionScene : public CBaseScene
{
public:
	Matrix m_matOrigin;

	float mouseX, mouseY;

	CText* m_SouudFX;
	CText* m_Music;
	CText* m_ScreenShake;
	CText* m_FullScreen;
	CText* m_ON;
	CText* m_OFF;
	CText* m_Exit;
	CText* m_barMusic;
	CText* m_barSound;
	CText* m_barScreen;

	CButtonObject m_SoundFXbar;
	CButtonObject m_soundFXbutton;
	CButtonObject m_MusicBar;
	CButtonObject m_ScreenShakeBar;
	CButtonObject m_ScreenShakeButton;

	CTimer changeScene;

public:
	OptionScene();
	~OptionScene();

	bool Initialize();
	void Terminate();
	bool Pulse();
	void ApiRender(Matrix mat);
};

