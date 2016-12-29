// File Name: ShapeAnimator.cpp
// Name of Author: Rachael Tjahjo
// Course Number and Name: CSE 220, Programming for Computer Engineering
// Semester: Fall 2016
// Lab Project Number: 2
// Time Spent: 10 hours 00 minutes
// NOTES: I used a Windows OS, and designed and tested in Microsoft Visual Studio
#include "stdafx.h"
#include "ShapeAnimator.h"

//***********************************************
// Shape methods                                *  
//***********************************************
void Shape::getDirection(int &drow, int &dcol) {
	drow = dRow;
	dcol = dCol;
}
void Shape::setDirection(int drow, int dcol) {
	dRow = drow;
	dCol = dcol;
}
void Shape::move(){
}


//***********************************************
// SimpleShape methods                          *  
//***********************************************
void SimpleShape::getPosition(int &row, int &col) {
	row = rowPos;
	col = colPos;
}
void SimpleShape::setPosition(int row, int col) {
	rowPos = row;
	colPos = col;
}
int SimpleShape::getColor() {
	return color;
}
void SimpleShape::setColor(int c) {
	color = c;
}

//*************************************************************
// Moves a simple shape one step by erasing the shape         *
// at its current position, changing its position, and then   *
// redrawing the shape at its new position.                   *
//*************************************************************
void SimpleShape::move()
{
	// Set cursor to current position 
	int pRow, pCol;
	getPosition(pRow, pCol);
	COORD pos;
	pos.X = pCol;
	pos.Y = pRow;
	SetConsoleCursorPosition(outHandle, pos);

	// Drawing in color 0 erases the shape
	int savedColor = getColor();
	setColor(0); 
	draw();

	int dRow, dCol; // Direction of motion
	getDirection(dRow, dCol);

	// Compute the new position for the shape by adding a step in
	// the proper direction to the current position
	pos.Y = pRow + dRow;
	// If else statement to deal with overflow: Overflow at bottow, back to 0, 
	// Overflow at top, back to 25
	if (pos.Y > 25) {
		pos.Y = 0;
	}
	else if (pos.Y < 0) {
		pos.Y = 25; 
	}

	pos.X = pCol + dCol;
	// If else statement to deal with overflow: Overflow to the right, back to 0, 
	// Overflow to the left, back to 80
	if (pos.X > 80) {
		pos.X = 0; 
	}
	else if (pos.X < 0) {
		pos.X = 80; 
	}

	SetConsoleCursorPosition(outHandle, pos);
	setPosition(pos.Y, pos.X);
		
	// Draw the shape at its new position in its specified color
	setColor(savedColor); 
	draw();

}

//***********************************************
// Box Constructor sets the color, position,    *
// dimensions for a box shape, and draws        *
// the box at its initial position              *
//***********************************************
Box::Box(int rPos, int cPos, int w, int h)
{
	setColor(4);
	rowPos = rPos;
	colPos = cPos;
	width = w;
	height = h;
	setDirection(0, 0);
}
//**********************************
// Draws a box shape               *
//**********************************
void Box::draw()
{
	// Set the current cursor position
	int rPos, cPos; 
	getPosition(rPos, cPos);

	COORD pos;
	pos.X = cPos;
	pos.Y = rPos;

	// Set the color attribute for the box
	SetConsoleTextAttribute(outHandle, getColor());

	// Draw the lines that make up the  box
	for (int c = 0; c < height; c++) {
		SetConsoleCursorPosition(outHandle, pos);
		for (int r = 0; r < width; r++)
		{
			cout << "* ";
		}
		pos.Y++; 
	}
}

//***********************************************
// Constructor sets the color for a Tent shape, *
// sets the position of the tent as well as the *
// length of its base and draws it at its       *
// initial position                             *
//***********************************************
Tent::Tent(int baseRowPos, int baseColPos, int bLength)
{
	setColor(2);
	rowPos = baseRowPos;
	colPos = baseColPos;
	baseLength = bLength;
	setDirection(0, 0);
}
//***********************************
// Draws a tent at its position     *
//***********************************
void Tent::draw()
{
	int pRow, pCol;
	getPosition(pRow, pCol);
	COORD pos;
	pos.X = pCol;
	pos.Y = pRow;

	// Set the color attribute
	SetConsoleTextAttribute(outHandle, getColor());

	// Draw the lines that form the tent beginning with
	// the base and moving up toward the point
	int e = 1;
	for (int i = baseLength; i > 0; i -= 2) {
		SetConsoleCursorPosition(outHandle, pos);
		for (int s = 0; s < i / 2; s++)
		{
			cout << "  ";
		}
		for (int s = 0; s < e; s++) {
			cout << "* ";
		}
		pos.Y++; 
		e = e + 2;
	}
}

//*********************************************************************
// Constructor builds a complex shape by assembling a vector of       *
// constituent shapes                                                 *
//*********************************************************************
ComplexShape::ComplexShape(Shape ** shapeCollection, int shapesCount)
{
	Shape *p;
	for (int k = 0; k < shapesCount; k++)
	{
		p = shapeCollection[k];
		shapes.push_back(p);
	}
}


//**************************************
// Moves a complex shape by moving the *
// constituent shapes                  *
//**************************************
void ComplexShape::move()
{
	Shape *p = shapes[0];

	int dRow, dCol;
	getDirection(dRow, dCol);

	for (int k = 0; k < shapes.size(); k++){
		p = shapes[k];
		p->setDirection(dRow, dCol); 
		p->move();
	}
	
}
void ComplexShape::setDirection(int dRow, int dCol){
	Shape::setDirection(dRow, dCol);
}

void ComplexShape::draw(){
	Shape *p; 
	for (int k = 0; k < shapes.size(); k++) {
		p = shapes[k]; 
		p->draw(); 
	}

}
