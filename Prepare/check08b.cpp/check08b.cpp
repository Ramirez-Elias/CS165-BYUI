/***********************************************************************
* Program:
* Assignment check08b
* Brother      , CS165
* Author:
* Elias Ramirez
*
* This checkpoint is intended to help you practice the syntax of 
* inheritance, specifically, the syntax of calling methods from a base 
* class.
************************************************************************/
/*****************
 * check08b.cpp
 *****************/

#include"phone.h"
#include "smartphone.h"

#include <iostream>
#include <string>
using namespace std;

/***************************************************
 * Function: main
 * Purpose: Tests a phone and a smart phone object.
 ***************************************************/
int main()
{
	//7 - In main function, create a Phone object, call its promptNumber
	//    method and then its display method.

	cout << "Phone:\n";

	// TODO: Create your Phone object here and call its promptNumber method
	Phone phone;
	phone.promptNumber();
	cout << "\nPhone info:\n";
	// TODO: Call your Phone's display method here
	phone.display();

	//8 - After that, also in main, create a SmartPhone object, call its prompt
	//    method and then its display method.
	cout << "\nSmart phone:\n";

	// TODO: Create your SmartPhone object here and call its prompt method
	SmartPhone smartPhone;
	smartPhone.prompt();

	cout << "\nPhone info:\n";
	// TODO: Call your SmartHpone's display method here
	smartPhone.display();


	return 0;
}