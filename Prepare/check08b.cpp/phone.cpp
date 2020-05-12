/*********************
 * phone.cpp
 *********************/
#include "phone.h"

 // TODO: Put your phone class methods here...

//2- The promptNumber method of the Phone class should ask the user to
//   enter each element of a phone number.

void Phone::promptNumber()
{
Phone:
	cout << "Area Code: ";
	cin >> this->areaCode;
	cout << "Prefix: ";
	cin >> this->prefix;
	cout << "Suffix: ";
	cin >> this->suffix;
}

//3- The display method of the Phone class should display the number in the
//   format "(areaCode)prefix-suffix".
void Phone::display()
{
	cout << "(" << this->areaCode << ")" << this->prefix << "-" 
		<< this->suffix << endl;

}
