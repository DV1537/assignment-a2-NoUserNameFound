#include "Triangle.h"

float Triangle::area() 
{
	return abs((getVertices()[0]*(getVertices()[3]- getVertices()[5])+ getVertices()[2]*(getVertices()[5]- getVertices()[1])+ getVertices()[4]*(getVertices()[1]- getVertices()[3]))/2);
}

float Triangle::circumference()
{
	float ab = sqrt(pow(getVertices()[0] - getVertices()[2], 2) + pow(getVertices()[1] - getVertices()[3], 2));
	float bc = sqrt(pow(getVertices()[2] - getVertices()[4], 2) + pow(getVertices()[3] - getVertices()[5], 2));
	float ac = sqrt(pow(getVertices()[0] - getVertices()[4], 2) + pow(getVertices()[1] - getVertices()[5], 2));

	return ab + bc + ac;
}

Triangle::Triangle(float x1, float y1, float x2, float y2, float x3,float y3)
{
	setType("Triangle");
	float* numbers = new float[6];
	numbers[0] = x1;
	numbers[1] = y1;
	numbers[2] = x2;
	numbers[3] = y2;
	numbers[4] = x3;
	numbers[5] = y3;
	setVert(numbers,6);
	setCenter((getVertices()[0]+ getVertices()[2]+ getVertices()[4])/3, (getVertices()[1] + getVertices()[3] + getVertices()[5]) / 3);
}

Triangle::~Triangle()
{
	deleting();
}
