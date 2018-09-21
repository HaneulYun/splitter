#pragma once

class GameoverScene : public CBaseScene
{
public:
	Matrix m_matOrigin;

	CText* m_TextFPS;
	CText* m_Gameover;
	CText* m_Score;
	CText* m_BestScore;
	CText* m_Exit;
	CText* m_Retry;

	float mouseX;
	float mouseY;

public:
	GameoverScene();
	~GameoverScene();

	bool Initialize();
	void Terminate();
	bool Pulse();
	void ApiRender(Matrix mat);
};

