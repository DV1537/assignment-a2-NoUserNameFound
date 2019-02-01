#include "Point.h"


float Point::area() 
{
	return -1;
}

float Point::circumference() 
{
	return 0;
}

Point::Point(float x,float y)
{
	setType("Point");
	float * numbers = new float[2];
	numbers[0] = x;
	numbers[1] = y;
	setVert(numbers,2);
	setCenter(getVertices()[0], getVertices()[1]);
	delete[] numbers;
}

Point::~Point()
{
	deleting();
}
