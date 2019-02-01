#include "Shape.h"

void Shape::setVert(float* verts, int number)
{

	vertices = new float[number];
	this->number = number;
	for (int i=0; i < number; i++)
	{
		vertices[i] = verts[i];
	}
	
}

void Shape::deleting()
{
	
	delete vertices;
	delete center;

}

int Shape::getNumber() const
{
	return number;
}

void Shape::setNumber(int number)
{
	this->number = number;
}

void Shape::setType(string type)
{
	this->type = type;
}

void Shape::setCenter(float x, float y)
{
	delete center;
	this->center = new float[2];
	center[0] = x;
	center[1] = y;
}

float * Shape::getVertices() const
{
	return vertices;
}

float* Shape::position() const
{
	return center;
}

string Shape::getType() const
{
	return type;
}

bool Shape::isConvex() const
{
	bool value = false;
	if (convex == true)
	{
		value = true;
	}
	return value;
}

float Shape::distance(Shape* shape)
{
	return sqrt(pow(center[0]-shape->position()[0],2)+pow(center[1]-shape->position()[1],2));
}


Shape & Shape::operator=( Shape & other)
{
	deleting();
	this->vertices = new float[other.number];

	setVert(other.vertices, other.number);
	
	this->number = other.number;
	return *this;
}

 ostream & operator<<(ostream & other, const Shape& shape)
{
	
 	other <<  "First shape vertices: ";
	for (int i = 0; i < shape.getNumber(); i++)
	{
		other << to_string(shape.vertices[i]) + " ";
	}

	return other;
}
