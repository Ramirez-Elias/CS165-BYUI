/*******************
 * smartphone.cpp
 *******************/

#include "smartphone.h"

 // TODO: Put your SmartPhone methods here

//5 - The prompt method of the SmartPhone class should call the promptNumber 
//    method defined in the base class and then additionally prompt for an 
//    email address.
void SmartPhone::prompt()
{
	promptNumber();
	cout << "Email: ";
	cin.ignore();
	getline(cin, this->email);
}
 
//6 - The display method of the SmartPhone class should call the display method
//    defined in the base class and then display the email address. (Yes, it must
//    call it, and yes they must both be named display.)
void SmartPhone::display()
{
	Phone::display() ;
	cout << this->email << endl;
}
