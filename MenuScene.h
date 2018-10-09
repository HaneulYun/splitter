#pragma once
#include "BaseScene.h"
#include "Text.h"
#include "ImageObject.h"

class MenuScene : public CBaseScene
{
public:
	Matrix m_matOrigin;

	CText* m_TextFPS;
	CText* m_TextSPLITTER;
	CText* m_TextEndless;
	CText* m_TextStage1;
	CText* m_TextCrazy;
	CText* m_TextStage3;
	CText* m_TextExit;
	CText* m_Option;

	CImageObject m_ImgTitle;
	CImageObject m_Nil;
	CImageObject m_JJang;

	float mouseX, mouseY;
	POINT mousePt;
public:
	MenuScene();
	~MenuScene();

	bool Initialize();
	void Terminate();
	bool Pulse();
	void ApiRender(Matrix mat);
};