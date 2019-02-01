#pragma once
#include"Shape.h"

using namespace std;

class Line : public Shape
{
public:
	float area() ;
	float circumference() ;
	Line(float x1, float y1, float x2, float y2);
	~Line();
};