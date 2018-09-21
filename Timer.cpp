#include "stdafx.h"

CTimer::CTimer(void)
{
}

CTimer::~CTimer(void)
{
}

void CTimer::InitTimer(DWORD dwDelayTime)
{
	m_dwOldTime = GetTickCount();
	m_dwDelayTime = dwDelayTime;
}

BOOL CTimer::IsElapseTimer()
{
	DWORD dwCurTime = GetTickCount();
	DWORD dwElapsed = dwCurTime - m_dwOldTime;

	if (dwElapsed >= m_dwDelayTime)
	{
		m_dwDelayTime = 0;
		m_dwOldTime = dwCurTime;
		return TRUE;
	}

	return FALSE;
}

BOOL CTimer::IsValidTimer()
{
	if (m_dwDelayTime)
		return TRUE;
	else
		return FALSE;
}