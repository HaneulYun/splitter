#include "stdafx.h"
#include "RedZoneFX.h"
#include "GameSceneBase.h"

CRedZoneFX::CRedZoneFX(Vector pt, int polyAngle, float distance, COLORREF color)
{
	m_eRenderType = eRenderType_Polygon;
	m_Color = color;

	m_Distance = distance;
	m_NumPolygon = 182;
	m_Polygon = new POINT[m_NumPolygon];
	for (int i = 0; i < 91; ++i)
	{
		m_Polygon[i] = { LONG(cosf(i / 45.f * PI) * m_Distance), LONG(sinf(i / 45.f * PI) * m_Distance) };
		m_Polygon[91 + i] = { LONG(cosf((90 - i) / 45.f * PI) * m_Distance * 0.8), LONG(sinf((90 - i) / 45.f * PI) * m_Distance * 0.8) };
		if ((i + 1) / 10 % 3 == 0)
			m_Polygon[i] = { LONG(cosf(i / 45.f * PI) * m_Distance * 0.8), LONG(sinf(i / 45.f * PI) * m_Distance * 0.8) };
	}


	m_scale = 1.0f;
	m_Point = pt;
	m_rotate = rand() % 200 / 100.0;

	m_Timer.InitTimer(2000);
}

CRedZoneFX::~CRedZoneFX()
{
	auto& con_enemy = g_pGameScene->m_EnemyManager->m_Enemy;

	for (auto iter = std::begin(con_enemy); iter != std::end(con_enemy);)
	{
		auto& enemy = *iter;
		enemy->m_Hp -= 30;

		if (enemy->m_Hp <= 0)
		{
			delete enemy;
			iter = con_enemy.erase(iter);
			continue;
		}

		++iter;
	}
}

bool CRedZoneFX::Initialize()
{
	return false;
}

void CRedZoneFX::Terminate()
{

}

bool CRedZoneFX::Pulse()
{
	m_rotate += 0.0035f;

	if (!m_Timer.IsValidTimer())  return false;
	if (!m_Timer.IsElapseTimer()) return false;

	return true;

}