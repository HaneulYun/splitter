#include "stdafx.h"
#include "BulletBase.h"

CBulletBase::CBulletBase()
{
	m_activeState = false;
	m_hp = 0;
	m_damage = 1.f;
}

CBulletBase::~CBulletBase()
{
}
