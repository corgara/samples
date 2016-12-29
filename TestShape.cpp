// File Name: TestShape.cpp
// Name of Author: Rachael Tjahjo
// Course Number and Name: CSE 220, Programming for Computer Engineering
// Semester: Fall 2016
// Lab Project Number: 2
// Time Spent: 10 hours 00 minutes
// NOTES: I used a Windows OS, and designed and tested in Microsoft Visual Studio
#include "stdafx.h"
#include "ShapeAnimator.h"

int main()
{
	// Create a tent and a box according to the requirements
	Tent tentObj(12, 5, 13);
	Box boxObj(5, 65, 4, 7);

	// Draw the tent and the box
	tentObj.draw();
	boxObj.draw();

	    // Simultaneously move the tent and the box
	    for (int k = 0; k < 10; k++)
	    {
	        Sleep(100);

			// Set direction of motion for the two shapes
			// Tent moves straight up
			tentObj.setDirection(0, k);
			tentObj.move();

			// Box moves horizontally to the left
			boxObj.setDirection(0, -k);
			boxObj.move();
	    }

		// Move the box farther to the right
		for (int k = 0; k < 9; k++)
		{
			Sleep(100);
			boxObj.setDirection(0, k);
			boxObj.move();
		}
		// Create a complex shape composed of the tent and the box
		// Hints: you need to plug in above myShapes array
	    Shape *myShapes[] = {&tentObj, &boxObj};
		ComplexShape shapeCollect(myShapes, 2);

	    // Move the complex shape: this will move both the tent and the box
	    for (int k = 0; k < 12; k++)
	    {
	        Sleep(100);
			shapeCollect.setDirection(0, k);
			shapeCollect.move();
	    }
		std::cin.ignore();

	    // Continue moving the box by itself
	    for (int k = 0; k < 36; k ++)
	    {
	        Sleep(100);
			boxObj.setDirection(0, k);
			boxObj.move();
	    }
	    return 0;
}

