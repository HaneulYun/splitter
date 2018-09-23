#pragma once

#include "Matrix.h"

class Vertex
{
public:
	union
	{
		struct
		{
			float x, y, w;
		};
		float v[3];
	};

public:
	Vertex();
	Vertex(float fx, float fy, float fw) { x = fx; y = fy; w = fw; }
	~Vertex();

	void Translate(Vertex v, Matrix max);
};

