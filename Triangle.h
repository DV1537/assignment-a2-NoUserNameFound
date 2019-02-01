#pragma once
#include"Shape.h"

using namespace std;

class Triangle : public Shape
{
public:
	float area() ;
	float circumference() ;
	Triangle(float x1, float y1, float x2, float y2, float x3, float y3);
	~Triangle();
};