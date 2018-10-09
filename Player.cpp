#include "stdafx.h"
#include "Player.h"
#include "GameSceneBase.h"
#include "ShellFX.h"
#include "RedZoneFX.h"

CPlayer::CPlayer()
{
	Initialize();
	for (auto& v : m_supporter)
		v.Initialize();
}

CPlayer::~CPlayer()
{
}

bool CPlayer::Initialize()
{
	m_eRenderType = eRenderType_Polygon;
	m_Color = RGB(0xff, 0xff, 0xff);

	m_Point = { 0, 0 };
	m_rotate = 0;
	m_scale = 1.0;

	old = GetTickCount();

	m_NumPolygon = 4;
	m_Polygon = new POINT[m_NumPolygon];
	{
		m_Polygon[0] = { -50, -50 };
		m_Polygon[1] = { -50,  50 };
		m_Polygon[2] = {  50,  50 };
		m_Polygon[3] = {  50, -50 };
	}

	m_WhirlWind = false;
	m_SuperSupporter = false;
	m_RedZone = false;
	m_gunType = 1;
	m_gunLevel = 1;

	m_normalSupporterDist = 200;
	m_normalSupporterPos = 0.0;
	return true;
}
void CPlayer::Terminate()
{

}
bool CPlayer::Pulse()
{
	if(m_gunLevel == 6)
		for (int i = 0; i < 2; ++i)
		{
			m_supporter[i].m_Point = { m_normalSupporterDist * cosf(PI * (m_normalSupporterPos + i)), m_normalSupporterDist * sinf(PI * (m_normalSupporterPos + i)) };
			m_supporter[i].Pulse();
		}
	m_normalSupporterPos += 0.005;
	if (g_pInputManager->m_MouseState.btn[0])
	{
		POINT mousePt;

		mousePt = g_pInputManager->m_mousePoint;

		m_rotate = atan2(mousePt.y - m_Point.y, mousePt.x - m_Point.x) / PI;

		switch (m_gunType)
		{
		case 1:
			if (GetTickCount() - old > 100)
			{
				old = GetTickCount();
				for (int i = 0; i < m_gunLevel; ++i)
					g_pGameScene->m_BulletManager->m_Bullet.push_back(new CBulletStraight(m_rotate - 0.075 + 0.15 / (m_gunLevel + 1) * (i + 1)));
				float t = m_rotate + 0.75 + rand() % 50 / 100.0;
				g_pGameScene->m_EffectManager->m_VFX.push_back(new CShellFX(m_Point, m_Color, rand() % 3000 + 2000, t));
				g_pGameScene->SetShake(100, 1.5, m_rotate);
				g_pSoundManager->Pulse(g_pGameScene->m_BulletManager->m_Bullet.back()->m_pChannel, 5);
			}
			break;
		case 2:
			if (GetTickCount() - old > 125)
			{
				old = GetTickCount();
				for (int i = 0; i < m_gunLevel; ++i)
					g_pGameScene->m_BulletManager->m_Bullet.push_back(new CBulletReflection(m_rotate - 0.075 + 0.15 / (m_gunLevel + 1) * (i + 1), 1));
				float t = m_rotate + 0.75 + rand() % 50 / 100.0;
				g_pGameScene->m_EffectManager->m_VFX.push_back(new CShellFX(m_Point, m_Color, rand() % 3000 + 2000, t));
				g_pGameScene->SetShake(100, 1.5, m_rotate);
				g_pSoundManager->Pulse(g_pGameScene->m_BulletManager->m_Bullet.back()->m_pChannel, 5);
			}
			break;
		case 3:
			if (GetTickCount() - old > 40)
			{
				old = GetTickCount();
				for (int i = 0; i < m_gunLevel; ++i)
					g_pGameScene->m_BulletManager->m_Bullet.push_back(new CBulletSprinkle(m_rotate - 0.075 + 0.15 / (m_gunLevel + 1) * (i + 1)));
				float t = m_rotate + 0.75 + rand() % 50 / 100.0;
				g_pGameScene->m_EffectManager->m_VFX.push_back(new CShellFX(m_Point, m_Color, rand() % 3000 + 2000, t));
				g_pGameScene->SetShake(100, 1.5, m_rotate);
				g_pSoundManager->Pulse(g_pGameScene->m_BulletManager->m_Bullet.back()->m_pChannel, 5);
			}
			break;
		case 4:
			if (GetTickCount() - old > 70)
			{
				old = GetTickCount();
				for (int i = 0; i < m_gunLevel; ++i)
					g_pGameScene->m_BulletManager->m_Bullet.push_back(new CBulletLaser(m_rotate - 0.075 + 0.15 / (m_gunLevel + 1) * (i + 1), 50));
				float t = m_rotate + 0.75 + rand() % 50 / 100.0;
				//g_pGameScene->m_EffectManager->m_VFX.push_back(new CShellFX(m_Point, m_Color, rand() % 3000 + 2000, t));
				g_pGameScene->SetShake(100, 1.5, m_rotate);
				g_pSoundManager->Pulse(g_pGameScene->m_BulletManager->m_Bullet.back()->m_pChannel, 8);
			}
			break;
		case 5:
			if (GetTickCount() - old > 200)
			{
				old = GetTickCount();
				g_pGameScene->m_BulletManager->m_Bullet.push_back(new CBulletBomb(m_rotate, 20));
				float t = m_rotate + 0.75 + rand() % 50 / 100.0;
				g_pGameScene->m_EffectManager->m_VFX.push_back(new CShellFX(m_Point, m_Color, rand() % 3000 + 2000, t));
				g_pGameScene->SetShake(100, 1.5, m_rotate);
				g_pSoundManager->Pulse(g_pGameScene->m_BulletManager->m_Bullet.back()->m_pChannel, 5);
			}
			break;
		case 6:
			if (GetTickCount() - old > 70 + (6 - m_gunLevel) * 30)
			{
				old = GetTickCount();
				g_pGameScene->m_BulletManager->m_Bullet.push_back(new CBulletGuided(m_rotate));
				float t = m_rotate + 0.75 + rand() % 50 / 100.0;
				g_pGameScene->m_EffectManager->m_VFX.push_back(new CShellFX(m_Point, m_Color, rand() % 3000 + 2000, t));
				g_pGameScene->SetShake(100, 1.5, m_rotate);
				g_pSoundManager->Pulse(g_pGameScene->m_BulletManager->m_Bullet.back()->m_pChannel, 5);
			}
			break;
		}
		switch (m_gunLevel)
		{
		case 1:
			if (g_pGameScene->m_Score > 50)
				m_gunLevel = 2;
			break;
		case 2:
			if (g_pGameScene->m_Score > 100)
				m_gunLevel = 3;
			break;
		case 3:
			if (g_pGameScene->m_Score > 150)
				m_gunLevel = 4;
			break;
		case 4:
			if (g_pGameScene->m_Score > 200)
				m_gunLevel = 5;
			break;
		case 5:
			if (g_pGameScene->m_Score > 250)
				m_gunLevel = 6;
			break;
		}
	}
	for(auto& v : g_pGameScene->m_EnemyManager->m_Enemy)
		if(v != nullptr && !v->m_type)
			if (v->hitBox(m_hitRect))
				if (v->hitPolyton(this, g_pGameScene->m_matWorld))
					g_pGameScene->m_isGameOver = true;
	if ((g_pKeyCodeScan('q') || g_pKeyCodeScan('Q')) && !m_RedZone)
	{
		m_RedZone = true;
		m_TimerRedZone.InitTimer(6000);
		for (int i = 0; i < 10; ++i)
		{
			float r = rand() % 200 / 100.f;
			float d = 400 + rand() % 600;
			g_pGameScene->m_EffectManager->m_VFX.push_back(new CRedZoneFX({d * cosf(r * PI), d* sinf(r * PI)}, 6, 250, RGB(255, 0.f, 0.f)));
		}
	}
	else if ((g_pKeyCodeScan('w') || g_pKeyCodeScan('W')) && !m_WhirlWind)
	{
		m_WhirlWind = true;
		m_rotateWhirlWind = 0;
		m_TimerWhirlWind.InitTimer(2000);

		for (int i = 0; i < 75; ++i)
		{
			m_rotateWhirlWind -= 0.05;
			for (int j = 0; j < 12; ++j)
				m_BulletWhirlWind.push_back(new CBulletStraight(m_rotateWhirlWind + 1.0 / 6 * j));
		}
	}
	else if ((g_pKeyCodeScan('e') || g_pKeyCodeScan('E')) && !m_SuperSupporter)
	{
		m_SuperSupporter = true;
		m_TimerSuperSupporter.InitTimer(8000);
	}
	if (m_WhirlWind) {
		if (m_TimerWhirlWind.IsValidTimer()) {
			if (GetTickCount() - m_OldBulletTime > 40) {
				m_OldBulletTime = GetTickCount();
				for (int i = 0; i < 12; ++i) {
					g_pGameScene->m_BulletManager->m_Bullet.push_back(m_BulletWhirlWind.front());
					m_BulletWhirlWind.pop_front();
				}
				g_pSoundManager->Pulse(g_pGameScene->m_BulletManager->m_Bullet.back()->m_pChannel, 5);
			}
			if (m_TimerWhirlWind.IsElapseTimer()) {
				m_WhirlWind = false;
				for (int i = 0; i < m_BulletWhirlWind.size(); ++i)
					delete m_BulletWhirlWind[i];
				m_BulletWhirlWind.clear();
			}
		}
	}
	if (m_SuperSupporter) {
		if (m_TimerSuperSupporter.IsValidTimer()) {
			for (int i = 2; i < 5; ++i) {
				m_supporter[i].m_Point = { m_normalSupporterDist * 2 * cosf(PI * (-m_normalSupporterPos * 0.4 + (i / 3.f * 2))), m_normalSupporterDist * 2 * sinf(PI * (-m_normalSupporterPos * 0.4 + (i / 3.f * 2))) };
				m_supporter[i].Pulse();
			}
			if (m_TimerSuperSupporter.IsElapseTimer()) {
				m_SuperSupporter = false;
			}
		}
	}
	if (m_RedZone)
		if (m_TimerRedZone.IsValidTimer())
			if (m_TimerRedZone.IsElapseTimer())
				m_RedZone = false;
	if (g_pKeyCodeScan('1'))
		m_gunType = 1;
	else if (g_pKeyCodeScan('2'))
		m_gunType = 2;
	else if (g_pKeyCodeScan('3'))
		m_gunType = 3;
	else if (g_pKeyCodeScan('4'))
		m_gunType = 4;
	else if (g_pKeyCodeScan('5'))
		m_gunType = 5;
	else if (g_pKeyCodeScan('6'))
		m_gunType = 6;
	return true;
}