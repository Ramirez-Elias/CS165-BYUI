/********************************************************************
 * File: date.cpp
 * Purpose: Holds the implementation of the Date class methods.
 ********************************************************************/

#include "date.h"

#include <iostream>
 // Put your method bodies here...

//Public Methods 
void Date:: displayAmerican()
{
	std::cout << this->month << "/"<< this->day << "/" << this->year << std::endl;
}

void Date::displayEuropean()
{
	std::cout << this->day << "/" << this->month << "/" << this->year << std::endl;
}
void Date::displayISO()
{
	std::cout << this->year  << "-" << this->month << "-" << this->day << std::endl;
}

//setters and getters
void Date::getMonth()
{
	std::cout << "Month: ";
	std::cin >> month;
}
void Date::setMonth(int month)
{
	this->month = month;
}
void Date::getDay()
{
	std::cout << "Day: ";
	std::cin >> day;
}
void Date::setDay(int day)
{
	this->day = day;
}
void Date::getYear()
{
	std::cout << "Year: ";
	std::cin >> year;
}
void Date::setYear(int year)
{
	this->year = year;
}

void Date::set()
{
	//set Method: Accepts a month, day, and year, and sets the member variables.
	getMonth();
	setMonth(month);
	getDay();
	setDay(day);
	getYear();
	setYear(year);
	std::cout << std::endl;
}

