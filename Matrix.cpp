#include "stdafx.h"

Matrix::Matrix()
{
}

Matrix::~Matrix()
{
}

Matrix Matrix::Zero()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			m[i][j] = 0.0f;
	return *this;
}

Matrix Matrix::Identity()
{
	Zero();
	m11 = 1.0f;		m22 = 1.0f;		m33 = 1.0f;
	return *this;
}

Matrix Matrix::Move(int dx, int dy)
{
	Identity();
	m31 = dx;		m32 = dy;		m33 = 1.0f;
	return *this;
}

Matrix Matrix::Scale(float s)
{
	Identity();
	m11 = s;		m22 = s;		m33 = 1.0f;
	return *this;
}
Matrix Matrix::Scale(float sx, float sy)
{
	Identity();
	m11 = sx;		m22 = sy;		m33 = 1.0f;
	return *this;
}
Matrix Matrix::Rotate(float fRadian)
{
	float radian = fRadian * PI; // *PI / 180.0; // 
	float c = cos(radian);
	float s = sin(radian);

	Identity();
	m11 = c;		m12 = s;
	m21 = -s;		m22 = c;
	return *this;
}
Matrix Matrix::Multiple(Matrix mat1)
{
	Matrix mat;

	mat.m11 = mat1.m11 * m11 + mat1.m12 * m21 + mat1.m13 * m31;
	mat.m12 = mat1.m11 * m12 + mat1.m12 * m22 + mat1.m13 * m32;
	mat.m13 = mat1.m11 * m13 + mat1.m12 * m23 + mat1.m13 * m33;
	mat.m21 = mat1.m21 * m11 + mat1.m22 * m21 + mat1.m23 * m31;
	mat.m22 = mat1.m21 * m12 + mat1.m22 * m22 + mat1.m23 * m32;
	mat.m23 = mat1.m21 * m13 + mat1.m22 * m23 + mat1.m23 * m33;
	mat.m31 = mat1.m31 * m11 + mat1.m32 * m21 + mat1.m33 * m31;
	mat.m32 = mat1.m31 * m12 + mat1.m32 * m22 + mat1.m33 * m32;
	mat.m33 = mat1.m31 * m13 + mat1.m32 * m23 + mat1.m33 * m33;

	m11 = mat.m11;
	m12 = mat.m12;
	m13 = mat.m13;
	m21 = mat.m21;
	m22 = mat.m22;
	m23 = mat.m23;
	m31 = mat.m31;
	m32 = mat.m32;
	m33 = mat.m33;

	return *this;
}

Matrix Matrix::operator+(const Matrix& rhs)
{
	Matrix mat;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			mat.m[i][j] = m[i][j] + rhs.m[i][j];
	return mat;
}

POINT Matrix::Translate(POINT p)
{
	POINT	temp;
	const float	w = 1.0f;

	temp.x = p.x * m11 + p.y * m21 + w * m31;
	temp.y = p.x * m12 + p.y * m22 + w * m32;

	return temp;
}