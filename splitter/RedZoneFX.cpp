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
		m_Polygon[91 + i] = { LONG(cosf((90-i) / 45.f * PI) * m_Distance * 0.8), LONG( sinf((90 - i) / 45.f * PI) * m_Distance * 0.8) };
		if((i+1)/10%3==0)
			m_Polygon[i] = { LONG(cosf(i / 45.f * PI) * m_Distance * 0.8), LONG(sinf(i / 45.f * PI) * m_Distance * 0.8) };
	}


	m_scale = 1.0f;
	m_Point = pt;
	m_rotate = rand() % 200 / 100.0;

	m_Timer.InitTimer(2000);
}

CRedZoneFX::~CRedZoneFX()
{
	auto& m_Enemy = g_pGameScene->m_EnemyManager->m_Enemy;
	for (int i = 0; i < m_Enemy.size(); ++i)
	{
		if (m_Enemy[i] == nullptr)
		{
			m_Enemy.erase(m_Enemy.begin() + i);
			--i;
			continue;
		}
		m_Enemy[i]->m_Hp -= 30;
		if (m_Enemy[i]->m_Hp <= 0)
		{
			delete m_Enemy[i];
			m_Enemy.erase(m_Enemy.begin() + i);
			--i;
			continue;
		}
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
	if (m_Timer.IsValidTimer())
	{
		if (m_Timer.IsElapseTimer())
		{
			return true;
		}
	}
	return false;
}