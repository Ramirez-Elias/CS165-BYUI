#include "rational.h"
#include <iostream>

void Rational::prompt()
{
	std::cout << "Top: ";
	std::cin >> top;
	std::cout << "Bottom: ";
	std::cin >> bottom;
}
//    B. Display the values in the format: "top/bottom".
void Rational::display()
{
	std::cout<< this->top << "/" << this->bottom << std::endl;
}
//    C. Display the value of the rational number in decimal format.
void Rational::displayDecimal()
{
	std::cout << (float)this->top / this->bottom << std::endl;
}
