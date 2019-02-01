#pragma once
#include"Shape.h"

using namespace std;

class Polygon : public Shape
{
public:
	Polygon(float* verts, float number);
	float circumference();
	float area();
	Polygon* operator+( Polygon const & other);
	~Polygon();
};