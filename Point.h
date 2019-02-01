#pragma once
#include"Shape.h"

using namespace std;

class Point : public Shape
{
private:

public:
	float area() ;
	float circumference() ;
	Point(float x, float y);
	~Point();
};