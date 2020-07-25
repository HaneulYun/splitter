#include "stdafx.h"
#include "BaseObject.h"

CBaseObject::CBaseObject()
{
}

CBaseObject::~CBaseObject()
{
}

bool CBaseObject::hitBox(RECT rt)
{
	if (this == nullptr)
		return false;
	if (!m_bIsHit)
		return false;
	if (m_hitRect.right < rt.left || m_hitRect.bottom < rt.top || m_hitRect.left > rt.right || m_hitRect.top > rt.bottom)
		return false;
	return true;
}

bool CBaseObject::hitPolyton(const CBaseObject* obj, Matrix matWorld)
{
	Matrix mat;
	std::vector<POINT> A{ };
	std::vector<POINT> B{ };

	A.resize(m_NumPolygon);
	B.resize(obj->m_NumPolygon);

	for (int i = 0; i < m_NumPolygon; ++i)
	{
		mat.Scale(m_scale);
		A[i] = mat.Translate(m_Polygon[i]);
		mat.Rotate(m_rotate);
		A[i] = mat.Translate(A[i]);
		mat.Move(m_Point.x, m_Point.y);
		A[i] = mat.Translate(A[i]);

		A[i] = matWorld.Translate(A[i]);
	}
	for (int i = 0; i < obj->m_NumPolygon; ++i)
	{
		mat.Scale(obj->m_scale);
		B[i] = mat.Translate(obj->m_Polygon[i]);
		mat.Rotate(obj->m_rotate);
		B[i] = mat.Translate(B[i]);
		mat.Move(obj->m_Point.x, obj->m_Point.y);
		B[i] = mat.Translate(B[i]);

		B[i] = matWorld.Translate(B[i]);
	}

	for (int k = 0; k < obj->m_NumPolygon; ++k)
	{
		int crosses = 0;
		for (int i = 0; i < m_NumPolygon; i++) {
			int j = (i + 1) % m_NumPolygon;						// �� B�� ���� (p[i], p[j])�� y��ǥ ���̿� ����
			if ((A[i].y > B[k].y) != (A[j].y > B[k].y))
			{													// atX�� �� B�� ������ ���򼱰� ���� (p[i], p[j])�� ����
				double atX = (A[j].x - A[i].x) * (B[k].y - A[i].y) / (A[j].y - A[i].y) + A[i].x;
				if (B[k].x < atX)	// atX�� ������ ���������� ������ ������ ������ ������ ������Ų��.
					crosses++;
			}
		}
		if (crosses % 2)
			return true;
	}

	for (int k = 0; k < m_NumPolygon; ++k)
	{
		int crosses = 0;
		for (int i = 0; i < obj->m_NumPolygon; i++) {
			int j = (i + 1) % obj->m_NumPolygon;						// �� B�� ���� (p[i], p[j])�� y��ǥ ���̿� ����
			if ((B[i].y > A[k].y) != (B[j].y > A[k].y))
			{													// atX�� �� B�� ������ ���򼱰� ���� (p[i], p[j])�� ����
				double atX = (B[j].x - B[i].x) * (A[k].y - B[i].y) / (B[j].y - B[i].y) + B[i].x;
				if (A[k].x < atX)	// atX�� ������ ���������� ������ ������ ������ ������ ������Ų��.
					crosses++;
			}
		}
		if (crosses % 2)
			return true;
	}
	return false;
}

Vector CBaseObject::normalVector(Vector vec, Matrix matWorld)
{
	Matrix mat;
	POINT* A = new POINT[m_NumPolygon];
	for (int i = 0; i < m_NumPolygon; ++i)
	{
		mat.Scale(m_scale);
		A[i] = mat.Translate(m_Polygon[i]);
		mat.Rotate(m_rotate);
		A[i] = mat.Translate(A[i]);
		mat.Move(m_Point.x, m_Point.y);
		A[i] = mat.Translate(A[i]);

		A[i] = matWorld.Translate(A[i]);
	}
	return {};
}