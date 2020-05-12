/***************
 * phone.h
 ***************/

#ifndef PHONE_H
#define PHONE_H
#include <iostream>
using namespace std;

 // TODO: Put your phone class definition here...

// 1- The Phone class should contain three integers for the different parts of a 
//    phone number. Here is its class diagram:
// -areaCode : int . - prefix : int . - suffix : int . + promptNumber() : void
// + display() : void
class Phone
{
public:
	Phone() {}
	~Phone() {}
	void promptNumber();
	void display();
private:
	int areaCode;
	int prefix;
	int suffix;
};




#endif