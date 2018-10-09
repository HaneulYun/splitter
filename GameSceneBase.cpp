#include "stdafx.h"
#include "GameSceneBase.h"

CGameSceneBase::CGameSceneBase()
{
	m_Player = NULL;
	m_BulletManager = NULL;
	m_EnemyManager = NULL;
	m_EffectManager = NULL;

	m_ShakeTime = 0;
	m_ShakeOffset = 0.0;
	m_Shaking = false;

	m_isGameOver = false;
	Initialize();
}

CGameSceneBase::~CGameSceneBase()
{
	Terminate();
}

bool CGameSceneBase::Initialize()
{
	Matrix mat;
	m_matWorld.Identity();
	m_matWorld.m11 = (float)g_pWindow->m_clientSize.cx / g_pWindow->m_winNormalRect.right * 0.32 *  cos(0.0);
	m_matWorld.m12 = (float)g_pWindow->m_clientSize.cx / g_pWindow->m_winNormalRect.right * 0.32 *  sin(0.0);
	m_matWorld.m21 = (float)g_pWindow->m_clientSize.cx / g_pWindow->m_winNormalRect.right * 0.32 * -sin(0.0);
	m_matWorld.m22 = (float)g_pWindow->m_clientSize.cx / g_pWindow->m_winNormalRect.right * 0.32 *  cos(0.0);
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

	m_Player = new CPlayer();
	m_BulletManager = new CBulletManager();
	m_EnemyManager = new CEnemyManager();
	m_EffectManager = new CEffectManager();

	m_TextSCORE = new CText();
	m_TextSCORE->FontInitialize(20, "Delta Universe-Regular", 90, 0);
	m_TextSCORE->ObjectInitialize(g_pWindow->m_clientSize.cx / 2, 10, RGB(0xff, 0xff, 0xff), RGB(0x00, 0x00, 0x00), 1);

	m_TextFPS = new CText();
	m_TextFPS->FontInitialize(20, "±¼¸²", 20, 0);
	m_TextFPS->ObjectInitialize(10, 10, RGB(0xff, 0xff, 0xff), RGB(0x00, 0x00, 0x00), 1);
	m_TextCNT = new CText();
	m_TextCNT->FontInitialize(20, "±¼¸²", 20, 0);
	m_TextCNT->ObjectInitialize(10, 30, RGB(0xcc, 0xcc, 0xcc), RGB(0x00, 0x00, 0x00), 1);
	m_TextVFX = new CText();
	m_TextVFX->FontInitialize(20, "±¼¸²", 20, 0);
	m_TextVFX->ObjectInitialize(10, 50, RGB(0x99, 0x99, 0x99), RGB(0x00, 0x00, 0x00), 1);
	m_TextENY = new CText();
	m_TextENY->FontInitialize(20, "±¼¸²",  20, 0);
	m_TextENY->ObjectInitialize(10, 70, RGB(0x66, 0x66, 0x66), RGB(0x00, 0x00, 0x00), 1);
	m_TextWAV = new CText();
	m_TextWAV->FontInitialize(20, "±¼¸²", 20, 0);
	m_TextWAV->ObjectInitialize(10, 90, RGB(0x33, 0x33, 0x33), RGB(0x00, 0x00, 0x00), 1);

	m_bullet1 = new CImageObject();
	m_bullet1->Initialize("resources/image/bullet1.jpg", -1850, 900, 1.0f);
	m_bullet2 = new CImageObject();
	m_bullet2->Initialize("resources/image/bullet2.jpg", -1850, 580, 1.0f);
	m_bullet3 = new CImageObject();
	m_bullet3->Initialize("resources/image/bullet3.jpg", -1850, 260, 1.0f);
	m_bullet4 = new CImageObject();
	m_bullet4->Initialize("resources/image/bullet4.jpg", -1850, -60, 1.0f);
	m_bullet5 = new CImageObject();
	m_bullet5->Initialize("resources/image/bullet5.jpg", -1850, -380, 1.0f);
	m_bullet6 = new CImageObject();
	m_bullet6->Initialize("resources/image/bullet6.jpg", -1850, -700, 1.0f);
	m_bullet7 = new CImageObject();
	m_bullet7->Initialize("resources/image/bullet7.jpg", -1850, -1020, 1.0f);
	m_skill1 = new CImageObject();
	m_skill1->Initialize("resources/image/skill1.jpg", -1500, 900, 1.0f);
	m_skill2 = new CImageObject();
	m_skill2->Initialize("resources/image/skill2.jpg", -1500, 580, 1.0f);
	m_skill3 = new CImageObject();
	m_skill3->Initialize("resources/image/skill3.jpg", -1500, 260, 1.0f);

	m_Score = 0;
	m_BestScore = 0;
	return true;
}

void CGameSceneBase::Terminate()
{
	m_TextFPS->Terminate();
	m_TextCNT->Terminate();
	m_TextVFX->Terminate();
	m_TextENY->Terminate();
	m_TextWAV->Terminate();
	m_TextSCORE->Terminate();

	m_bullet1->Terminate();
	m_bullet2->Terminate();
	m_bullet3->Terminate();
	m_bullet4->Terminate();
	m_bullet5->Terminate();
	m_bullet6->Terminate();
	m_bullet7->Terminate();

	m_skill1->Terminate();
	m_skill2->Terminate();
	m_skill3->Terminate();

	m_EffectManager->Terminate();
	m_EnemyManager->Terminate();
	m_BulletManager->Terminate();
	m_Player->Terminate();
}

bool CGameSceneBase::Pulse()
{
	update(g_pSystem->GetTimeStep() * 1000);
	m_matWorld = m_matOrigin;
	m_matWorld.m31 += actual.x;
	m_matWorld.m32 += actual.y;

	m_EffectManager->Pulse();
	m_Player->Pulse();
	m_BulletManager->Pulse();
	m_EnemyManager->Pulse();


	char str[20];
	sprintf(str, "%d", m_Score);
	m_TextSCORE->Pulse(str);
	sprintf(str, "FPS : %.2f", g_pSystem->GetFPS());
	m_TextFPS->Pulse(str);
	sprintf(str, "CNT : %4d", m_BulletManager->m_Bullet.size());
	m_TextCNT->Pulse(str);
	sprintf(str, "VFX : %4d", m_EffectManager->m_VFX.size());
	m_TextVFX->Pulse(str);
	sprintf(str, "ENY : %4d", m_EnemyManager->m_Enemy.size());
	m_TextENY->Pulse(str);
	int cnt;
	g_pSoundManager->soundSystem->getChannelsPlaying(&cnt);
	sprintf(str, "WAV : %4d", cnt);
	m_TextWAV->Pulse(str);

	if ((g_pKeyCodeScan('m') || g_pKeyCodeScan('M')))
		g_pSystem->ChangeProcess(eProcessType_MenuScene);
	if (m_isGameOver)
	{
		g_pSystem->m_Score = m_Score;
		g_pSystem->m_BestSocre = m_BestScore;
		g_pSystem->ChangeProcess(eProcessType_GameoverScene);
	}
	return true;
}

void CGameSceneBase::ApiRender(Matrix mat)
{
	m_bullet1->Render(mat);
	m_bullet2->Render(mat);
	m_bullet3->Render(mat);
	m_bullet4->Render(mat);
	m_bullet5->Render(mat);
	m_bullet6->Render(mat);
	m_bullet7->Render(mat);

	m_skill1->Render(mat);
	m_skill2->Render(mat);
	m_skill3->Render(mat);

	m_EffectManager->Render(mat);
	m_EnemyManager->Render(mat);
	m_BulletManager->Render(mat);
	m_Player->Render(mat);

	m_TextSCORE->Render(mat);
	m_TextFPS->Render(mat);
	m_TextCNT->Render(mat);
	m_TextVFX->Render(mat);
	m_TextENY->Render(mat);
	m_TextWAV->Render(mat);
}

void CGameSceneBase::SetShake(int shakeTime, float shakeOffset, float radian)
{
	if (m_Shaking)
		if (m_ShakeOffset > shakeOffset)
			return;
	m_ShakeTime = shakeTime;
	m_ShakeOffset = shakeOffset;
	m_ShakingRadian = radian;
	m_Shaking = true;
}
void CGameSceneBase::update(int delta)
{
	if (m_Shaking)
		updateShake(delta);
	else
		actual.x = actual.y = 0;
}

void CGameSceneBase::updateShake(int delta) {
	if (shakeTimer == 0)
		xOffset = yOffset = Offset = 0;

	shakeTimer += delta;
	if (shakeTimer > m_ShakeTime)
		shakeTimer = m_Shaking = xOffset = yOffset = Offset = 0;
	else
		applyScreenShake(delta);
}

void CGameSceneBase::applyScreenShake(int delta) {
	//Depending on shake direction, the screen is moved either to the top left, or the bottom right
	if (m_ShakeDirection)
	{
		Offset -= 0.75 * delta;
		if (Offset < -m_ShakeOffset)
		{
			Offset = -m_ShakeOffset * 2 * g_pSystem->m_abc;
			xOffset = Offset * cos(m_ShakingRadian * PI);
			yOffset = Offset * sin(m_ShakingRadian * PI);
			m_ShakeDirection = !m_ShakeDirection;
		}
	}
	else
	{
		Offset += 0.75 * delta;
		if (Offset > m_ShakeOffset)
		{
			Offset = m_ShakeOffset * 2 * g_pSystem->m_abc;
			xOffset = Offset * cos(m_ShakingRadian * PI);
			yOffset = Offset * sin(m_ShakingRadian * PI);
			m_ShakeDirection = !m_ShakeDirection;
		}
	}
	actual.x = xOffset;
	actual.y = yOffset;
}
