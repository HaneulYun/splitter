#pragma once

class Vector
{
public:
	float x;
	float y;

public:
	Vector();
	Vector(float a, float b);
	~Vector();

	float distance(const Vector rhs);
	float dot(const Vector rhs);
};