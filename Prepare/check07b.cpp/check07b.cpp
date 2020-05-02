/***********************************************************************
* Program:
* Assignment check07b
* Brother      , CS165
* Author:
* Elias Ramirez
*
* This checkpoint is intended to help you practice the the syntax of 
* pointers and dynamic allocation.
************************************************************************/
/***********************************************************************
* File: check07b.cpp
************************************************************************/

#include <iostream>
using namespace std;

#include "voxel.h"
#include "world.h"

/**************************************************************
 * Function: main
 * Purpose: The driver for the program. Creates a world, sets
 *  some Voxels and displays them.
 **************************************************************/
int main()
{
	cout << "Starting Program.\n";

	// 1. Add code here to declare a World


	// 2. Add code here to call the world's display function

	// See page 70 in the book for details on how to access methods
	// in pointers.

	// (*newWorld).display(); // dot notation method with parenthesis operators

	/* You CANNOT just do this:
	World w;
	w.display();
	*/

	// First, we create a voxel for air


	// 3. Call setBox on your world to put the air at spot (50, 60, 70)


	// Next, we create a voxel for grass


	// 4. Call setBox on your world to put the grass at spot (45, 20, 10)


	// 5. Call world's displayBox twice, once for each of these spots


	// 6. Finally, make sure to free up your memory by deleting the world


	cout << "Ending Program.\n";
	return 0;
}
