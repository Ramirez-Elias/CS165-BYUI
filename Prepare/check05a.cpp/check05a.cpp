/***********************************************************************
* Program:
* Assignment check05a
* Brother      , CS165
* Author:
* Elias Ramirez
*
* This checkpoint is intended to help you practice the syntax of getters
* and setters. In particular, you will be provided the code of a class 
* and your assignment is to add getters and setters to it.
*
* Add Getters and Setters to an existing Money class that holds dollars 
* and cents.
************************************************************************/

 // You should not change anything in this file 


#include <iostream>
using namespace std;

#include "money.h"

/****************************************************************
 * Function: main
 * Purpose: Test the money class
 ****************************************************************/
int main()
{
	Money money;

	money.prompt();
	money.display();

	cout << endl;

	cout << "That is " << money.getDollars() << " dollars and "
		<< money.getCents() << " cents!\n";

	return 0;
}