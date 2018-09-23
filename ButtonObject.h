#pragma once
#include "BaseObject.h"

class CButtonObject : public CBaseObject
{
public:
	enum eButtonType {
		eButtonType_scroll,
		eButtonType_button,
	};
public:
	CButtonObject();
	~CButtonObject();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;

	bool Initialize(float x, float y, COLORREF RGB, eButtonType );

};

