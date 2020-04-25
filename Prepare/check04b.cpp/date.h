/********************************************************************
 * File: date.h
 * Purpose: Holds the definition of the Date class.
 ********************************************************************/

#ifndef DATE_H
#define DATE_H

 // put your class definition here
 // along with the data members, and method prototypes

//1- Create a class called "Date" with the following private data members:
//   month - day - year

class Date
{
// 2- Create the following public methods(functions) :
//	  set - Accepts a month, day, and year, and sets the member variables.
//    displayAmerican - Displays the date in the format : mm / dd / yyyy .
//	  displayEuropean - Displays the date in the format : dd / mm / yyyy .
//	  displayISO - Displays the date in the format : yyyy - mm - dd .
public:
	//Public Methods 
	void displayAmerican();
	void displayEuropean();
	void displayISO();

	//setters and getters
	void getMonth();
	void setMonth(int month);
	void getDay();
	void setDay(int day);
	void getYear();
	void setYear(int year);
	
	//set Method: Accepts a month, day, and year, and sets the member variables.
	void set();

private:
	int month;
	int day;
	int year;
};

#endif