#include "Polygon.h"

Polygon::Polygon(float* verts, float number)
{
	setType("Triangle");
	float* numbers = new float[number];
	for (int i = 0; i < number; i++)
	{
		numbers[i] = verts[i];
	}
	setVert(numbers, number);
	setCenter(0, 0); 
	delete[] numbers;
}

float Polygon::circumference()
{
	float value = 0;
	bool changed = false;
	for (int i = 0; i < getNumber()-2; i+=2)
	{
		value += sqrt(pow(getVertices()[i] - getVertices()[i+2], 2) + pow(getVertices()[i] - getVertices()[i+2], 2));
		changed = true;
	}
	if (changed)
	{
		value+= sqrt(pow(getVertices()[getNumber()-2] - getVertices()[0], 2) + pow(getVertices()[getNumber() - 1] - getVertices()[1], 2));
	}

	return value;
}

float Polygon::area()
{
	float value = -1;
	if (!isConvex())
	{
		float number1 = 0;
		float number2 = 0;
		for (int i = 0; i < getNumber()-2; i+=2)
		{
			number1 += getVertices()[i] * getVertices()[i + 3];
			number2 += getVertices()[i + 1] * getVertices()[i + 2];
		}
		number1 += getVertices()[getNumber() - 2] * getVertices()[1];
		number2 += getVertices()[getNumber() - 1] * getVertices()[0];
		value = (number2 - number1)/2;
	}
	return value;
}

Polygon*  Polygon::operator+(  Polygon const & other)
{

	float* temp = new float[getNumber()+other.getNumber()];
	for (int i = 0; i < getNumber(); i++)
	{
		temp[i] = getVertices()[i];
	}
	for (int i = getNumber(); i < getNumber() + other.getNumber(); i++)
	{
		temp[i] = other.getVertices()[i - other.getNumber()];

	}
	deleting();
	setVert(temp, getNumber()+other.getNumber());
	delete temp;
	return this;
}

Polygon::~Polygon()
{
	//deleting();
}
