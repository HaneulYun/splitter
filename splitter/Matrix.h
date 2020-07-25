#pragma once
#include "Vector.h"
#include "stdafx.h"

class Matrix
{
public:
	union
	{
		struct
		{
			float m11, m12, m13;
			float m21, m22, m23;
			float m31, m32, m33;
		};
		float m[3][3];
	};

public:
	Matrix();
	~Matrix();

	Matrix Zero();
	Matrix Identity();
	Matrix Move(int dx, int dy);
	Matrix Scale(float s);
	Matrix Scale(float sx, float sy);
	Matrix Rotate(float fRadian);
	Matrix Multiple(Matrix mat1);

	Matrix operator+(const Matrix& mat);

	POINT Translate(POINT p);
	Vector Translate(Vector p);
};

