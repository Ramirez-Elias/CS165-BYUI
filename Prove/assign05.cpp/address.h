/***************************************************************
 * File: address.h
 * Author: Elias Ramirez
 * Purpose: Contains the definition of the Address class
 ***************************************************************/
#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>
#include <string>
using namespace std;
 //2. Create a class for an Address that has the following 
 //   private data members: 
 //   street : string - city : string - state : string - zip : string

class Address
{
public:
	//It should also have the following constructors:
	//Default - Set the street to "unknown", the zip to "00000", and the other data members to "".
	//Non-default - Accept 4 strings (street, city, state, zip) and set each of the values.
	Address() : street("unknown"), zip("00000"), city(""), state("") {};
	Address(string street, string city, string state, string zip);
	~Address() {};
	string getStreet();
	void setStreet(string street);
	string getCity();
	void setCity(string city);
	string getState();
	void setState(string state);
	string getZip();
	void setZip(string zip);
	// -Displays the address in the format : 
	//street
	//city, state zip
	void display();


private:
	string street;
	string city;
	string state;
	string zip;

};


#endif