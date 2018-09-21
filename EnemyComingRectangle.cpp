#include "stdafx.h"

CEnemyComingRectangle::CEnemyComingRectangle()
{
	m_moveSpeed = 0.0f;
	m_moveDirection = 0.0f;
	Initialize();
}

CEnemyComingRectangle::~CEnemyComingRectangle()
{
	Terminate();
}

bool CEnemyComingRectangle::Initialize()
{
	m_eRenderType = eRenderType_Polygon;
	m_Color = RGB(0xff, 0xff, 0xff);

	m_NumPolygon = 4;
	m_Polygon = new POINT[m_NumPolygon];
	{
		m_Polygon[0] = { -50, -50 };
		m_Polygon[1] = { -50,  50 };
		m_Polygon[2] = { 50,  50 };
		m_Polygon[3] = { 50, -50 };
	}
	m_scale = 1.0f;

	m_moveSpeed = 0;
	m_moveDirection = atan2(-m_Point.y, -m_Point.x) / PI;
	m_rotate = m_moveDirection;

	m_Hp = 2;
	m_AddScore = 2;

	state = 0;

	return true;
}
void CEnemyComingRectangle::Terminate()
{
	g_pSoundManager->Pulse(m_pChannel, 6);
	g_pGameScene->SetShake(100, 5, m_rotate);
	g_pGameScene->m_EffectManager->m_VFX.push_back(new CTearFX(m_Point, 200, 6, m_Color));
	g_pGameScene->m_EffectManager->m_VFX.push_back(new CDestroyFX(m_Point, m_NumPolygon, 200, m_Color));
}
bool CEnemyComingRectangle::Pulse()
{
	CEnemyBase::Pulse();

	m_moveSpeed += g_pSystem->GetTimeStep() * (!state ? 1200 : -800);
	if (m_moveSpeed > 400)
	{
		m_moveSpeed = 400;
		state = 1;
	}
	else if (m_moveSpeed < 0)
	{
		m_moveSpeed = 0;
		state = 0;
	}
	m_Point.x += g_pSystem->GetTimeStep() * m_moveSpeed * cos(m_moveDirection * PI);
	m_Point.y += g_pSystem->GetTimeStep() * m_moveSpeed * sin(m_moveDirection * PI);
	return false;
}