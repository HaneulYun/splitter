#include "stdafx.h"
#include "RedLineFX.h"
#include "WndSystem.h"
#include "GameSceneBase.h"
#include "EnemyComingFastSpear.h"

CRedLineFX::CRedLineFX()
{
	m_eRenderType = eRenderType_Polygon;
	m_Color = RGB(0xff, 0x00, 0x00);

	
	m_NumPolygon = 4;
	m_Polygon = new POINT[m_NumPolygon];
	m_TargetPolygon = new POINT[m_NumPolygon];
	{
		m_TargetPolygon[0] = m_Polygon[0] = { LONG(0), LONG(-80) };
		m_TargetPolygon[1] = m_Polygon[1] = { LONG(0), LONG(80) };
		m_TargetPolygon[2] = m_Polygon[2] = { LONG(4000), LONG(80) };
		m_TargetPolygon[3] = m_Polygon[3] = { LONG(4000), LONG(-80) };
	}

	m_createRotate = rand() % 200 / 100.0;
	float radius = sqrt(pow(g_pGameScene->m_worldRect.right, 2) + pow(g_pGameScene->m_worldRect.bottom, 2));
	m_createPoint = { float(radius * cos(m_createRotate*PI)), float(radius * sin(m_createRotate*PI)) };
	m_Point = { 0, 0 };

	m_scale = 1.0f;
	m_rotate = m_createRotate ;

	m_InnerRatio = 0.0f;
	m_OuterRatio = 0.0f;

	m_Timer.InitTimer(400);
}


CRedLineFX::~CRedLineFX()
{
	g_pGameScene->m_EnemyManager->m_Enemy.push_back(new CEnemyComingFastSpear(m_createPoint));
}

bool CRedLineFX::Initialize()
{
	return false;
}
void CRedLineFX::Terminate()
{
}
bool CRedLineFX::Pulse()
{
	if (m_Timer.IsValidTimer())
	{
		float ratio = 1.0 / 400 * (GetTickCount() - m_Timer.m_dwOldTime);
		float rInner = 1 - sin(ratio * PI / 2);
		//float rOuter = sin(PI * (1.5 + ratio / 2)) + 1;
		//float rOuter = ratio;
		for (int i = 0; i < m_NumPolygon; ++i)
		{
			m_Polygon[i] = { LONG(m_TargetPolygon[i].x * 1.f), LONG(m_TargetPolygon[i].y * rInner) };
		}
		if (m_Timer.IsElapseTimer())
		{
			return true;
		}
	}
	return false;
}