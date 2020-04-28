/***********************
 * File: money.cpp
 ***********************/
#include "money.h"
#include <iostream>
#include <iomanip>



/*****************************************************************
 * Function: prompt
 * Purpose: Asks the user for values for dollars and cents
 *   and stores them.
 ****************************************************************/
void Money::prompt()
{
	int dollars;
	int cents;

	std::cout << "Dollars: ";
	std::cin >> dollars;

	std::cout << "Cents: ";
	std::cin >> cents;

	setDollars(dollars);
	setCents(cents);
}

/*****************************************************************
 * Function: display
 * Purpose: Displays the value of the money object.
 ****************************************************************/
void Money::display() const
{
	std::cout << "$" << getDollars() << ".";
	std::cout << std::setfill('0') << std::setw(2) << getCents();
}

//getters
int Money::getDollars() const
{
	return dollars;
}
int Money::getCents() const
{
	return cents;
}

//5. If negative values are passed to either of your setters, you should set the
//   value to be positive (e.g., setting -3 dollars, will result in 3 dollars).
//setters
void Money::setDollars(int dollars) 
{
	if (dollars <= 0) 
		this->dollars = -(dollars);
	else
		this->dollars = dollars;
}
void Money::setCents(int cents)
{
	if (cents <= 0)
		this->cents = -(cents);
	else
		this->cents = cents;
}