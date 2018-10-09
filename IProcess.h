#pragma once
#include "stdafx.h"
#include "Matrix.h"

class IProcess
{
public:
	enum eProcessType
	{
		eProcessType_Unknown,
		eProcessType_LoadScene,
		eProcessType_MenuScene,
		eProcessType_GameScene,
		eProcessType_Stage01Scene,
		eProcessType_CrazyScene,
		eProcessType_GameoverScene,
		eProcessType_OptionScene,
		eProcessType_NILScene,
		eProcessType_Quit,
		eProcessType_Count,
	};

public:
	eProcessType m_eType;

public:
	IProcess()
	{
		m_eType = eProcessType_Unknown;
	}

	virtual ~IProcess()
	{
	}

	inline void SetType(eProcessType eType);
	inline eProcessType GetType() const;

	virtual bool Initialize() = 0;
	virtual void Terminate() = 0;
	virtual bool Pulse() = 0;
	virtual void Render() = 0;

	virtual Matrix GetMatrix() const = 0;
	virtual RECT GetRect() const = 0;
};

__inline void IProcess::SetType(eProcessType eType)
{
	m_eType = eType;
}

__inline IProcess::eProcessType IProcess::GetType() const
{
	return m_eType;
}