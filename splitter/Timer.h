#pragma once

class CTimer
{
public:
	DWORD m_dwOldTime;
	DWORD m_dwDelayTime;
public:
	CTimer(void);
	virtual ~CTimer(void);

	void InitTimer(DWORD dwDelayTime);
	BOOL IsElapseTimer();
	BOOL IsValidTimer();
};