/***********************************************************************
* Program:
* Assignment teach08
* Brother      , CS165
* Author:
* Elias Ramirez
*
* Instructions:
* Create a class to represent a Circle, based on a provided Point class.
* It has a center (x, y), and a radius. Because a Circle has an x and a 
* y coordinate, and more, one way to view it, would be to consider that  
* a Circle IS-A Point. In this case, the Circle class would inherit from 
* the Point class, and simply add a radius to it.
************************************************************************/
#include <iostream>
#include "circle.h"

using namespace std;

/***********************************************************
 * Function: Main
 * Prompts for a circle and displays it.
 ***********************************************************/
int main()
{
	Circle circle;

	circle.promptForCircle();

	cout << "Your circle is:\n";
	circle.display();

	cout << "\n\n";

	// Test a getter
	// This comes for free with the is-a relationship
	// You need to create it for the has-a relationship
	cout << "The x-coordinate of your circle is: " << circle.getX() << endl;

	return 0;
}