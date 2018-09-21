#pragma once

#define g_pGameScene dynamic_cast<CGameSceneBase*>(dynamic_cast<CBaseScene*>(g_pSystem->m_pCurProcess))

class CGameSceneBase : public CBaseScene
{
public:
	CPlayer* m_Player;
	CBulletManager* m_BulletManager;
	CEnemyManager* m_EnemyManager;
	CEffectManager* m_EffectManager;

	int m_Score;
	int m_isGameOver;

	CText* m_TextSCORE;
	CText* m_TextFPS;
	CText* m_TextCNT;
	CText* m_TextVFX;
	CText* m_TextENY;
	CText* m_TextWAV;

	CImageObject* m_bullet1;
	CImageObject* m_bullet2;
	CImageObject* m_bullet3;
	CImageObject* m_bullet4;
	CImageObject* m_bullet5;
	CImageObject* m_bullet6;
	CImageObject* m_bullet7;
	CImageObject* m_skill1;
	CImageObject* m_skill2;
	CImageObject* m_skill3;

	Matrix m_matOrigin;

	float Offset = 0;
	float xOffset = 0;
	float yOffset = 0;
	int shakeTimer = 0;

	Vector actual;

	int m_ShakeTime;
	float m_ShakeOffset;
	float m_ShakingRadian;
	boolean m_ShakeDirection = false;
	boolean m_Shaking;
public:
	CGameSceneBase();
	~CGameSceneBase();

	bool Initialize();
	void Terminate();
	bool Pulse();
	void ApiRender(Matrix mat);

	void SetShake(int shakeTime, float shakeOffset, float radian);
	void update(int delta);
	void updateShake(int delta);
	void applyScreenShake(int delta);
};

