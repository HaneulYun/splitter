#include "Vertex.h"

Vertex::Vertex()
{
}

Vertex::~Vertex()
{
}

void Vertex::Translate(Vertex v, Matrix mat)
{
	x = v.x * mat.m11 + v.y * mat.m21 + v.w * mat.m31;
	y = v.x * mat.m12 + v.y * mat.m22 + v.w * mat.m32;
	w = 1.0;
}