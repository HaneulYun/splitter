#pragma once

class IntroScene : public CBaseScene
{
public:
	Matrix m_matOrigin;

	CText* m_hello;
	CText* m_Nil;
	CText* m_jang;
	CText* m_people;
	CText* m_people1;

	int initSound;
public:
	IntroScene();
	~IntroScene();

	bool Initialize();
	void Terminate();
	bool Pulse();
	void ApiRender(Matrix mat);
};

