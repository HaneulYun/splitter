#include "stdafx.h"
#include "EnemyRotatingTriangleShield.h"
#include "GameSceneBase.h"

CEnemyRotatingTriangleShield::CEnemyRotatingTriangleShield()
{
	m_moveSpeed = 0.0f;
	m_rotateSpeed = 0.0f;
	m_moveDirection = 0.0f;
	Initialize();
}

CEnemyRotatingTriangleShield::~CEnemyRotatingTriangleShield()
{
	Terminate();
}

bool CEnemyRotatingTriangleShield::Initialize()
{
	m_eRenderType = eRenderType_Polygon;
	m_Color = RGB(0xff, 0xff, 0xff);

	m_NumPolygon = 32;
	m_Polygon = new POINT[m_NumPolygon];
	for (int i = 0; i < m_NumPolygon / 2; ++i)
	{
		m_Polygon[i] =					  { 100 + LONG(142 * cos(PI * 2 / 48 * (i-7))), 0 + LONG(142 * sin(PI * 2 / 48 * (i-7))) };
		m_Polygon[m_NumPolygon - i - 1] = { 100 + LONG(150 * cos(PI * 2 / 48 * (i-7))), 0 + LONG(150 * sin(PI * 2 / 48 * (i-7))) };
	}

	m_rotate = 0.0f;
	m_scale = 1.0f;

	m_moveSpeed = 120;
	m_rotateSpeed = rand() % 2 ? 0.3 : -0.3f;
	m_moveDirection = atan2(-m_Point.y, -m_Point.x) / PI;

	m_Hp = 50000;
	m_AddScore = 0;

	m_type = true;

	return true;
}
void CEnemyRotatingTriangleShield::Terminate()
{
	g_pGameScene->m_EffectManager->m_VFX.push_back(new CTearFX(m_Point, 600, 15, m_Color));
	g_pGameScene->m_EffectManager->m_VFX.push_back(new CDestroyFX(m_Point, m_NumPolygon * 2, 600, m_Color));
}
bool CEnemyRotatingTriangleShield::Pulse()
{
	CEnemyBase::Pulse();

	m_Point.x += g_pSystem->GetTimeStep() * m_moveSpeed * cos(m_moveDirection * PI);
	m_Point.y += g_pSystem->GetTimeStep() * m_moveSpeed * sin(m_moveDirection * PI);

	m_rotate += g_pSystem->GetTimeStep() * m_rotateSpeed;
	return false;
}