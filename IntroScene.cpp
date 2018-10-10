#include "stdafx.h"
#include "IntroScene.h"
#include "WndSystem.h"

#define WIDTH_NORMALIZE(x) (-m_worldRect.right/2+m_worldRect.right*(x/1280.f))
#define HEIGHT_NORMALIZE(y) (-m_worldRect.bottom/2+m_worldRect.bottom*(y/720.f))

IntroScene::IntroScene()
{
}

IntroScene::~IntroScene()
{
	Terminate();
}

bool IntroScene::Initialize()
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

	m_hello = new CText;
	m_hello->FontInitialize(100, "고딕", 40, 0);
	m_hello->ObjectInitialize(WIDTH_NORMALIZE(100), HEIGHT_NORMALIZE(100), RGB(160, 250, 255), RGB(0x00, 0x00, 0x00), 1);
	

	m_Nil = new CText;
	m_Nil->FontInitialize(100, "고딕", 40, 0);
	m_Nil->ObjectInitialize(WIDTH_NORMALIZE(750), HEIGHT_NORMALIZE(100), RGB(160, 250, 255), RGB(0x00, 0x00, 0x00), 1);

	m_jang = new CText;
	m_jang->FontInitialize(100, "고딕", 40, 0);
	m_jang->ObjectInitialize(WIDTH_NORMALIZE(400), HEIGHT_NORMALIZE(200), RGB(160, 250, 255), RGB(0x00, 0x00, 0x00), 1);

	m_people = new CText;
	m_people->FontInitialize(100, "고딕", 40, 0);
	m_people->ObjectInitialize(WIDTH_NORMALIZE(300), HEIGHT_NORMALIZE(300), RGB(160, 250, 255), RGB(0x00, 0x00, 0x00), 1);
	
	m_people1 = new CText;
	m_people1->FontInitialize(100, "고딕", 40, 0);
	m_people1->ObjectInitialize(WIDTH_NORMALIZE(80), HEIGHT_NORMALIZE(400), RGB(160, 250, 255), RGB(0x00, 0x00, 0x00), 1);

	initSound = 0;
	return true;
}
void IntroScene::Terminate()
{
	if (m_hello) {
		m_hello->Terminate();
		m_hello = nullptr;
	}
	if (m_Nil) {
		m_Nil->Terminate();
		m_Nil = nullptr;
	}
	if (m_jang) {
		m_jang->Terminate();
		m_jang = nullptr;
	}
	if (m_people) {
		m_people->Terminate();
		m_people = nullptr;
	}
	if (m_people1) {
		m_people1->Terminate();
		m_people1 = nullptr;
	}
}
bool IntroScene::Pulse()
{
	char str[100];

	sprintf(str, "안녕하세요! 저희는 splitter 제작자");
	m_hello->Pulse(str);
	sprintf(str, "윤하늘, 장수현입니다.");
	m_Nil->Pulse(str);
	sprintf(str, "copyright.split bullet");
	m_jang->Pulse(str);
	sprintf(str, "이 게임을 만드는데 도움을 주신분들");
	m_people->Pulse(str);
	sprintf(str, "윤정훈 남주영 이예은 최아도 최홍일 이상기 송주희 송인희 김민주");
	m_people1->Pulse(str);

	if (g_pSystem->m_pSoundManager == nullptr && initSound)
	{
		g_pSystem->m_pSoundManager = new CSoundManager();
		g_pSystem->ChangeProcess(eProcessType_MenuScene);
	}

	return true;
}
void IntroScene::ApiRender(Matrix mat)
{
	m_hello->Render(mat);
	m_Nil->Render(mat);
	m_jang->Render(mat);
	m_people->Render(mat);
	m_people1->Render(mat);

	if (initSound == 0)
		initSound = 1;
}
