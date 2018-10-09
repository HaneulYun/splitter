#include "stdafx.h"
#include "BulletLaser.h"
#include "WndSystem.h"
#include "GameSceneBase.h"


CBulletLaser::CBulletLaser(float direction, float time)
{
	//m_direction = direction + (rand() % 100 / 5000.0) - 0.01;
	m_direction = direction + (rand() % 100 / 2000.0) - 0.025;
	m_speed = 0;

	Initialize();

	m_validTime.InitTimer(time);
}


CBulletLaser::~CBulletLaser()
{
	Terminate();
}

bool CBulletLaser::Initialize()
{
	m_eRenderType = eRenderType_Polygon;
	m_Color = RGB(0xff, 0xff, 0xff);

	m_Point = { 0, 0 };
	m_rotate = m_direction;
	m_scale = 1.0;

	m_damage = g_pSystem->GetTimeStep() * 20;

	m_NumPolygon = 122;
	m_Polygon = new POINT[m_NumPolygon];
	{
		for (int i = 0; i < 61; ++i)
		{
			m_Polygon[i] = { i * 50, -4 };
			m_Polygon[61 + i] = { 3000 - i * 50, 4 };
		}
	}

	return true;
}

void CBulletLaser::Terminate()
{
}

bool CBulletLaser::Pulse()
{
	if (!m_activeState) m_activeState = true;
	m_damage = g_pSystem->GetTimeStep() * 20;
	if (m_validTime.IsValidTimer())
		if (m_validTime.IsElapseTimer())
			return true;
	return false;
}
