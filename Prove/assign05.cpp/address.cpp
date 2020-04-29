/***************************************************************
 * File: address.cpp
 * Author: Elias Ramirez
 * Purpose: Contains the method implementations for the address
 * class.
 ***************************************************************/
#include "address.h"

//Non-default - Accept 4 strings (street, city, state, zip) and 
//set each of the values.
Address::Address(string street, string city, string state, string zip)
{
	this->street = street;
	this->city = city;
	this->state = state;
	this-> zip = zip;
}


string Address:: getStreet()
{
	return this->street; 
}

void Address::setStreet(string street)
{
	this->street = street;
}

string Address::getCity()
{
	return this->city;
}

void Address::setCity(string city)
{
	this->city = city;
}

string Address:: getState()
{
	return this->state;
}

void Address:: setState(string state)
{
	this->state = state;
}

string Address:: getZip()
{
	return this->zip;
}

void Address:: setZip(string zip)
{
	this->zip = zip;
}
// -Displays the address in the format : 
//street
//city, state zip
void Address::display()
{
	cout << getStreet() << endl;
	cout << getCity() << ", " << getState() << " " << getZip() << endl;
}
