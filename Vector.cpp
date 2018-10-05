#include <iostream.>
#include "Vector.h"

Vector::Vector() : x(0.0f), y(0.0f)
{
}

Vector::Vector(float a, float b) : x(a), y(b)
{
}

Vector::~Vector()
{
}

float Vector::distance(const Vector rhs)
{
	return sqrt(pow(rhs.x - x, 2) + pow(rhs.y - y, 2));
}

float Vector::dot(const Vector rhs)
{
	return x * rhs.x + y * rhs.y;
}