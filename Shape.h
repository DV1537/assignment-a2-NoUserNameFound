#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<cmath>

using namespace std;


class Shape
{
	float* vertices;
	string type;
	float* center;
	int number;
	bool convex;
public:
	void setVert(float* verts, int number);
	void deleting();
	int getNumber() const;
	void setNumber(int number);
	void setType(string type);
	void setCenter(float x, float y);
	float* getVertices() const;
	float* position() const;
	virtual string getType() const;
	virtual float area()  =0;
	virtual float circumference() =0;
	bool isConvex() const;
	float distance(Shape* shape);
	Shape& operator=( Shape& other);
	friend ostream& operator<<( ostream & other, const Shape& shape);
};