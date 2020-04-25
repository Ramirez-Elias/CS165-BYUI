/***********************************************************************
* Program:
* Assignment check04b
* Brother      , CS165
* Author:
* Elias Ramirez
*
* This checkpoint is intended to help you practice the syntax of creating
* your own class. For this checkpoint, you need to put all of your code 
* in separate files. Then you will need to "tar them up" into a single .tar
* file and submit it.
*
* Write a C++ program that has a class for a date, that holds a month, 
* day, and year, and can display it in American format (mm/dd/yyyy), 
* European format (dd/mm/yyyy), and the ISO 8601 standard format 
* (yyyy-mm-dd).
************************************************************************/
#include "date.h"
#include <iostream>
#include <string>


/***********************************************************************
* MAIN:
* 4- Have main:
*    A. Prompt the user for a month, day, and year.
*    B. Create a Date object.
*    C. Call the set method on your object, passing in the month, day, 
*       and year.
*    D. Call the displayAmerican, displayEuropean, and displayISO 
*       methods on your object.
************************************************************************/
int main()
{
	Date date;
	date.set();
	date.displayAmerican();
	date.displayEuropean();
	date.displayISO();
	return 0;
}

