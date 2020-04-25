#ifndef DATE_H
#define DATE_H

/***********************************************************************
* 1- Put your class in separate files:
*    rational.h - Contains the class definition / prototypes
*    rational.cpp - Contains the bodies of the functions
*    ta04.cpp - Contains main
* 3- Add the following data members: int top and int bottom.
************************************************************************/
class Rational
{
public:
	//4 - Add the following functions. Make sure to put their prototypes 
	//    in the .h file, and their bodies in the .cpp file.
	//    A. Ask the user to enter the top and the bottom. Save these in
	//       the member variables.
	void prompt();
	//    B. Display the values in the format: "top/bottom".
	void display();
	//    C. Display the value of the rational number in decimal format.
	void displayDecimal();

private:
	int top;
	int bottom;
};

#endif
