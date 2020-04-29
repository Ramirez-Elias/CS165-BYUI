/***************************************************************
 * File: customer.h
 * Author: Elias Ramirez
 * Purpose: Contains the definition of the Customer class
 ***************************************************************/
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include"address.h"
#include <iostream>
#include <string>
using namespace std;

//3. Create a class for a Customer that has the following private 
//   data members: name: string - address : Address

class Customer
{
public:
	//Default - Set the name to "unspecified" and uses the address's 
	//default constructor.
	Customer() : name("unspecified"), address() {};
	Customer(string name, Address address);
	~Customer() {};
	string getName();
	void setName(string name);
	Address getAddress();
	void setAddress(Address address);
	void display();

private:
	string name;
	Address address;
};


#endif
