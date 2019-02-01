#include "Line.h"

float Line::area() 
{
	return -1;
}

float Line::circumference() 
{
	return 0;
}

Line::Line(float x1, float y1, float x2, float y2)
{
	float* numbers = new float[4];
	numbers[0] = x1;
	numbers[1] = y1;
	numbers[2] = x2;
	numbers[3] = y2;
	setType("Line");
	setVert(numbers , 4);
	setCenter(getVertices()[0]+(getVertices()[2]- getVertices()[0])/2, getVertices()[1] + (getVertices()[3] - getVertices()[1]) / 2);
}

Line::~Line()
{
	deleting();
}
