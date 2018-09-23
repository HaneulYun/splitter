#include "stdafx.h"
#include "NILScene.h"
#include "WndSystem.h"

NILScene::NILScene()
{
	Initialize();
}

NILScene::~NILScene()
{
	Terminate();
}

bool NILScene::Initialize()
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

	m_Nilcongratulation.Initialize("resources/image/ÇÏ´Ã1.jpg", -290, -650, 1.5f);
	m_happy.Initialize("resources/image/nil/happy.jpg", -1170, -650, 1.27f);
	m_birthday.Initialize("resources/image/nil/birthday.jpg", 890, -650, 1.2f);
	m_nil1.Initialize("resources/image/nil/À±.jpg", -1200, 300, 1.0f);
	m_nil2.Initialize("resources/image/nil/ÇÏ.jpg", 0, 300, 1.0f);
	m_nil3.Initialize("resources/image/nil/´Ã.jpg", +1200, 300, 1.0f);

	return true;
}

void NILScene::Terminate()
{
	m_Nilcongratulation.Terminate();
	m_happy.Terminate();
	m_birthday.Terminate();
	m_nil1.Terminate();
	m_nil2.Terminate();
	m_nil3.Terminate();
}

bool NILScene::Pulse()
{
	m_Nilcongratulation.Pulse();
	m_happy.Pulse();
	m_birthday.Pulse();

	m_nil3.Pulse();
	m_nil1.Pulse();
	m_nil2.Pulse();

	if ((g_pKeyCodeScan('m') || g_pKeyCodeScan('M')))
		g_pSystem->ChangeProcess(eProcessType_MenuScene);
	return true;
}

void NILScene::ApiRender(Matrix mat)
{
	m_Nilcongratulation.Render(mat);
	m_happy.Render(mat);
	m_birthday.Render(mat);
	m_nil1.Render(mat);
	m_nil2.Render(mat);
	m_nil3.Render(mat);
}