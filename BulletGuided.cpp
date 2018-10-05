#include "stdafx.h"
#include "BulletGuided.h"
#include "WndSystem.h"
#include "GameSceneBase.h"

CBulletGuided::CBulletGuided(float direction)
{
	m_direction = direction + (rand() % 100 / 5000.0) - 0.01;
	m_speed = 2500;

	Initialize();
}

CBulletGuided::~CBulletGuided()
{
	Terminate();
}

bool CBulletGuided::Initialize()
{
	m_eRenderType = eRenderType_Polygon;
	m_Color = RGB(0xff, 0xff, 0xff);

	m_Point = { 0, 0 };
	m_rotate = m_direction;
	m_scale = 1.0;
	m_damage = 1.f;

	left = right = false;

	m_NumPolygon = 4;
	m_Polygon = new POINT[m_NumPolygon];
	{
		m_Polygon[0] = { -20, -20 };
		m_Polygon[1] = { -56,   0 };
		m_Polygon[2] = { -20,  20 };
		m_Polygon[3] = {  56,   0 };
	}

	return true;
}
void CBulletGuided::Terminate()
{
	if (m_activeState)
		g_pGameScene->m_EffectManager->m_VFX.push_back(new CDestroyFX(m_Point, 6, 70, m_Color));
}
bool CBulletGuided::Pulse()
{
	if (!m_activeState) m_activeState = true;


	if (g_pGameScene->m_EnemyManager->m_Enemy.size() > 0)
	{
		CEnemyBase* bs = nullptr;
		Vector target;
		float distance = -1;
		for (int i = 0; i < g_pGameScene->m_EnemyManager->m_Enemy.size(); ++i)
		{
			if(g_pGameScene->m_EnemyManager->m_Enemy[i])
				if (float dist = m_Point.distance(g_pGameScene->m_EnemyManager->m_Enemy[i]->m_Point); (dist < distance || distance < 0) && dist < 1600)
				{
					Vector vec{ cosf(m_rotate*PI), sinf(m_rotate*PI) };
					Vector vec2{ float(g_pGameScene->m_EnemyManager->m_Enemy[i]->m_Point.x - m_Point.x), float(g_pGameScene->m_EnemyManager->m_Enemy[i]->m_Point.y - m_Point.y) };
					if (vec.dot(vec2) < -400)
						continue;

					distance = dist;
					target = g_pGameScene->m_EnemyManager->m_Enemy[i]->m_Point;
					bs = g_pGameScene->m_EnemyManager->m_Enemy[i];
				}
		}
		if (distance > 0 && distance < 1600)
		{
			Vector vec{ cosf((m_rotate+0.5)*PI), sinf((m_rotate+0.5)*PI) };
			Vector vec2{ bs->m_Point.x - m_Point.x, bs->m_Point.y - m_Point.y };
			//if (!timerLeft.IsValidTimer() && !timerRight.IsValidTimer())
			//{
				if (vec.dot(vec2) < 0)
				{
					timerLeft.InitTimer(4000);
					timerRight.InitTimer(0);
				}
				else
				{
					timerRight.InitTimer(4000);
					timerLeft.InitTimer(0);
				}
			//}
			float r = 1 - (1.f / 1600 * distance);
			m_Color = RGB(0xff, (1-r)*0xff, (1 - r) *0xff);
			if(bs)
				bs->m_Color = RGB(0xff, (1 - r) * 0xff, (1 - r) * 0xff);
		}
		else
			m_Color = RGB(0xff, 0xff, 0xff);
	}

	timerLeft.IsElapseTimer();
	timerRight.IsElapseTimer();
	if (timerLeft.IsValidTimer())
	{
		m_direction -= 0.6 * g_pSystem->GetTimeStep();
		m_rotate = m_direction;
	}
	if (timerRight.IsValidTimer())
	{
		m_direction += 0.6 *g_pSystem->GetTimeStep();
		m_rotate = m_direction;
	}

	m_Point.x += g_pSystem->GetTimeStep() * m_speed * cos(m_direction * PI);
	m_Point.y += g_pSystem->GetTimeStep() * m_speed * sin(m_direction * PI);

	POINT pt = { m_Point.x, m_Point.y };
	pt = g_pSystem->m_pCurProcess->GetMatrix().Translate(pt);

	if (pt.x + 60 < 0 || pt.y + 60 < 0 ||
		pt.x - 60 > +g_pWindow->m_clientSize.cx || pt.y - 60 > +g_pWindow->m_clientSize.cy)
		return true;
	return false;
}