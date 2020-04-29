/***************************************************************
 * File: customer.cpp
 * Author: Elias Ramirez
 * Purpose: Contains the method implementations for the customer
 * class.
 ***************************************************************/
#include "customer.h"

//Non - default - Accept a name and an address object.
Customer::Customer(string name, Address address)
{
	this->name = name;
	this->address = address;
}

void Customer::display()
{
	cout << getName() << endl;
	address.display();
	
}

string Customer::getName()
{
	return this->name;
}
void Customer::setName(string name)
{
	this->name = name;
}
Address Customer::getAddress()
{
	return this->address;
}

void Customer::setAddress(Address address)
{
	this->address = address;
}