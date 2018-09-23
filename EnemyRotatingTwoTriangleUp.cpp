#include "stdafx.h"
#include "EnemyRotatingTwoTriangleUp.h"
#include "EnemyRotatingTwoTriangleDown.h"
#include "GameSceneBase.h"

CEnemyRotatingTwoTriangleUp::CEnemyRotatingTwoTriangleUp()
{
	m_moveSpeed = 0.0f;
	m_rotateSpeed = 0.0f;
	m_moveDirection = 0.0f;
	Initialize();
}

CEnemyRotatingTwoTriangleUp::~CEnemyRotatingTwoTriangleUp()
{
	Terminate();
}

bool CEnemyRotatingTwoTriangleUp::Initialize()
{
	m_eRenderType = eRenderType_Polygon;
	m_Color = RGB(0xff, 0xff, 0xff);

	m_NumPolygon = 3;
	m_Polygon = new POINT[m_NumPolygon];
	{
		m_Polygon[0] = {  150, -150 };
		m_Polygon[1] = { -150,  150 };
		m_Polygon[2] = {  150,  150 };
	}

	m_rotate = 0.0f;
	m_scale = 1.0f;

	m_moveSpeed = 120;
	m_rotateSpeed = rand() % 2 ? 0.3 : -0.3f;
	m_moveDirection = atan2(-m_Point.y, -m_Point.x) / PI;

	m_Hp = 25;
	m_AddScore = 4;

	g_pGameScene->m_EnemyManager->m_Enemy.push_back(new CEnemyRotatingTwoTriangleDown());
	dynamic_cast<CEnemyRotatingTwoTriangleDown*>(g_pGameScene->m_EnemyManager->m_Enemy.back())->m_rotateSpeed = m_rotateSpeed;
	dynamic_cast<CEnemyRotatingTwoTriangleDown*>(g_pGameScene->m_EnemyManager->m_Enemy.back())->m_moveDirection = m_moveDirection;
	g_pGameScene->m_EnemyManager->m_Enemy.back()->m_Point = m_Point;

	return true;
}
void CEnemyRotatingTwoTriangleUp::Terminate()
{
	g_pSoundManager->Pulse(m_pChannel, 6);
	g_pGameScene->SetShake(150, 15, m_rotate);
	g_pGameScene->m_EffectManager->m_VFX.push_back(new CTearFX(m_Point, 600, 10, m_Color));
	g_pGameScene->m_EffectManager->m_VFX.push_back(new CDestroyFX(m_Point, m_NumPolygon * 2, 600, m_Color));
}
bool CEnemyRotatingTwoTriangleUp::Pulse()
{
	CEnemyBase::Pulse();

	m_Point.x += g_pSystem->GetTimeStep() * m_moveSpeed * cos(m_moveDirection * PI);
	m_Point.y += g_pSystem->GetTimeStep() * m_moveSpeed * sin(m_moveDirection * PI);

	m_rotate += g_pSystem->GetTimeStep() * m_rotateSpeed;
	return false;
}