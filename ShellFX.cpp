#include "stdafx.h"
#include "ShellFX.h"
#include "WndSystem.h"

CShellFX::CShellFX(Vector pt, COLORREF color, float speed, float direction)
{
	m_eRenderType = eRenderType_Polygon;
	m_Color = color;

	m_NumPolygon = 4;
	m_Polygon = new POINT[m_NumPolygon];
	m_TargetPolygon = new POINT[m_NumPolygon];
	{
		m_TargetPolygon[0] = m_Polygon[0] = { -9, -23 };
		m_TargetPolygon[1] = m_Polygon[1] = { -9,  23 };
		m_TargetPolygon[2] = m_Polygon[2] = { 9,  23 };
		m_TargetPolygon[3] = m_Polygon[3] = { 9, -23 };
	}

	m_scale = 1.0f;
	m_Point = pt;
	m_rotate = rand() % 200 / 100.0;

	m_moveSpeed = speed;

	m_rotateSpeed = rand() % 200 / 100.0f;
	m_moveDirection = direction;

	m_Timer.InitTimer(2000);
}

CShellFX::~CShellFX()
{
}

bool CShellFX::Initialize()
{
	return false;
}
void CShellFX::Terminate()
{

}
bool CShellFX::Pulse()
{
	if (m_Timer.IsValidTimer())
	{
		float ratio = 1.0 / m_Timer.m_dwDelayTime * (GetTickCount() - m_Timer.m_dwOldTime);
		m_Point.x += g_pSystem->GetTimeStep() * m_moveSpeed * cos(m_moveDirection * PI);
		m_Point.y += g_pSystem->GetTimeStep() * m_moveSpeed * sin(m_moveDirection * PI);
		m_rotate += g_pSystem->GetTimeStep() * m_rotateSpeed;
		m_moveSpeed -= g_pSystem->GetTimeStep() * m_moveSpeed * 7;

		m_Polygon[0].y = m_TargetPolygon[0].y + 23 * sin(ratio*PI / 2);
		m_Polygon[1].y = m_TargetPolygon[1].y - 23 * sin(ratio*PI / 2);
		m_Polygon[2].y = m_TargetPolygon[2].y - 23 * sin(ratio*PI / 2);
		m_Polygon[3].y = m_TargetPolygon[3].y + 23 * sin(ratio*PI / 2);
		if (m_Timer.IsElapseTimer())
		{
			return true;
		}
	}

	return false;
}