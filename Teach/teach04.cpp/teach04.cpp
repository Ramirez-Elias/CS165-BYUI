/***********************************************************************
* Program:
* Assignment teach04
* Brother      , CS165
* Author:
* Elias Ramirez
*
* Instructions:
* As a team, write a class to represent a rational number (i.e., a 
* fraction).
************************************************************************/
#include "rational.h"
#include <iostream>

/***********************************************************************
* MAIN:
************************************************************************/
int main()
{
	Rational rational;
	rational.prompt();
	rational.display();
	rational.displayDecimal();
	return 0;
}

