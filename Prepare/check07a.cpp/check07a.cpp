/***********************************************************************
* Program:
* Assignment check07a
* Brother      , CS165
* Author:
* Elias Ramirez
*
* This checkpoint is intended to help you practice the syntax of 
* constructors. It will build upon the class you created in Checkpoint
* 05a..
*
* Add a default and a non-default constuctor the Money class from 
* Checkpoint 05a.
************************************************************************/
/**********************
 * File: check07a.cpp
 **********************/

#include <iostream>
#include <string>
using namespace std;
#include "icecream.h"

//4. Give this variable a default value of 0.06.
float IceCream::salesTax = 0.06;

/*****************************************
 * Function: Main
 * Purpose: Tests the Ice Cream class
 *****************************************/

int main()
{
	IceCream iceCream1;
	iceCream1.prompt();

	IceCream iceCream2;
	iceCream2.prompt();

	cout << "\nMenu:\n";
	iceCream1.display();
	iceCream2.display();
	cout << endl;

	float tax;
	cout << "Enter alternate sales tax: ";
	cin >> tax;
	//6- A main function is provided for you in check07a.cpp. It declares 
	//   two IceCream objects, displays them, asks for an alternate sales tax,
	//   and displays them again. Currently (because you hadn't written it yet), 
	//   it does not actually change the sales tax value.
	//7- Change main, where noted in the comments, to actually set the new sales
	//   tax value.
	iceCream1.salesTax = tax;
	iceCream2.salesTax = tax;

	cout << "\nMenu:\n";
	iceCream1.display();
	iceCream2.display();

	return 0;
}