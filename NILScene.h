#pragma once

class NILScene : public CBaseScene
{
public:
	Matrix m_matOrigin;

	CImageObject m_Nilcongratulation;
	CImageObject m_happy;
	CImageObject m_birthday;
	CImageObject m_nil1;
	CImageObject m_nil2;
	CImageObject m_nil3;


public:
	NILScene();
	~NILScene();

	bool Initialize();
	void Terminate();
	bool Pulse();
	void ApiRender(Matrix mat);
};

