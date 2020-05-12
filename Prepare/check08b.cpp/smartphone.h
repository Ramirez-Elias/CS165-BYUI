/****************
 * smartphone.h
 ****************/
#include <iostream>
#include <string>
#include "phone.h"
using namespace std;

#ifndef SMARTPHONE_H
#define SMARTPHONE_H

 // TODO: Put your SmartPhone definition here

//4 - The SmartPhone class should extend the Phone class and add the following:
//    -email : string . + prompt() : void . + display() : void

class SmartPhone : public Phone
{
public:
	SmartPhone() {}
	~SmartPhone() {}
	void prompt(); 
	void display();
private:
	string email;
};





#endif