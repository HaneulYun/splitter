#pragma once
#include "BaseObject.h"

class CImageObject : public CBaseObject
{
public:
	CImageObject();
	~CImageObject();

	virtual bool Initialize() override;
	virtual void Terminate() override;
	virtual bool Pulse() override;

	bool Initialize(char* url, float x, float  y, float scale);
};

