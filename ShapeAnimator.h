// File Name: ShapeAnimator.h
// Name of Author: Rachael Tjahjo
// Course Number and Name: CSE 220, Programming for Computer Engineering
// Semester: Fall 2016
// Lab Project Number: 2
// Time Spent: 10 hours 00 minutes
// NOTES: I used a Windows OS, and designed and tested in Microsoft Visual Studio
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

// A global constant
// It is the handle to the output console
const HANDLE outHandle = GetStdHandle(STD_OUTPUT_HANDLE);

// A shape has a direction and is able to move in that direction.
// The move is a virtual member function.
class Shape
{
private:
	int dRow, dCol;
public:
	void setDirection(int, int);
	virtual void getDirection(int &, int &);
	virtual void move() = 0;
	virtual void draw() = 0; 
};

// A SimpleShape can be drawn at a given position in a specified color
// A SimpleShape inherits from Shape class
class SimpleShape :public Shape
{
protected:
	int rowPos, colPos, color;
public:
	void getPosition(int &, int &);
	void setPosition(int, int);
	int getColor();
	void setColor(int);
	void move();
};

// A Box is a rectangular type of shape
// A Box inherits from SimpleShape
class Box :public SimpleShape
{
private:
	int width, height;
public:
	Box(int, int, int, int);
	virtual void draw();
};

// A Tent is an isosceles triangle whose horizontal base has a
// given length and whose height is half the length of the base.
// The position of the triangle is the left endpoint of the base
// A Tent inherits from SimpleShape
class Tent :public SimpleShape
{
private:
	int baseLength;
public:
	Tent(int, int, int);
	virtual void draw();
};

// A ComplexShape is made up of simpler shapes. It is represented
// as a vector of pointers to the simpler shapes that make it up
// A ComplexShape inherits from Shape
class ComplexShape:public Shape
{
private:
	vector<Shape *> shapes;
public:
	ComplexShape(Shape ** shapeCollection, int shapesCount);
	    virtual void move();
	    virtual void setDirection(int, int); 
		virtual void draw(); 
}; 
