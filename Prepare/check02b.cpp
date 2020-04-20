/***********************************************************************
* Program:
* Assignment check02b
* Brother      , CS165
* Author:
* Elias Ramirez
*
* Sample Output
* The following is an example of output for this program:
* Real: 3
* Imaginary: 5
* Real: 2.1
* Imaginary: 6.2
*
* The sum is: 5.1 + 11.2i
************************************************************************/
#include <iostream>
#include <iomanip>

/***********************************************************************
* Struct Complex
* Create a struct for a Complex number that has a real part (a double) 
* and an imaginary part (a double).
************************************************************************/
struct Complex
{
	double realNumber;
	double imagNumber;
};

//Prototyping
Complex prompt();
Complex addComplex(Complex * c1, Complex * c2);
void displayComplex(Complex * sum);

/***********************************************************************
* MAIN:
************************************************************************/
int main()
{
	//1- Declare two objects of type Complex called c1 and c2.
	Complex c1 = {};
	Complex c2 = {};

	//2- Call your prompt function twice to fill in the values for c1 
	//and c2.
	c1 = prompt();
	c2 = prompt();

	//3- Call your addComplex function to produce the sum.
	Complex * pC1;
	Complex * pC2;
	
	pC1 = &c1;
	pC2 = &c2;

	Complex sum = addComplex(pC1, pC2);
	Complex * pSum;
	pSum = &sum;

	//4- Call your display function to display the sum.
	displayComplex(pSum);

	return 0;
}

/***********************************************************************
* Complex prompt()
* Write a function, prompt, to prompt the user for the real and 
* imaginary parts of complex number, and have it return a Complex struct.
************************************************************************/
Complex prompt()
{
	Complex c = {};
	std::cout << "Real: ";
	std::cin >> c.realNumber;
	std::cout << "Imaginary: ";
	std::cin >> c.imagNumber;
	return c;
}

/***********************************************************************
* displayComplex()
* Write a function, display, that accepts a Complex struct and displays 
* it in the format: "2.1 + 3.2i". You need not worry about handling zero
* or negatives at this point.
************************************************************************/
void displayComplex(Complex * sum)
{
	std::cout << "The sum is: " << sum->realNumber << " + " 
		<< sum->imagNumber << "i"<< std::endl;
}

/***********************************************************************
* addComplex()
* Fill in the body for the function, addComplex, that accepts two complex
* numbers and returns their sum. Remember that when adding complex 
* numbers, the real parts are added and the imaginary parts are added.
************************************************************************/
Complex addComplex(Complex * c1, Complex * c2)
{
	Complex sum = {};
	sum.realNumber = c1->realNumber + c2->realNumber;
	sum.imagNumber = c1->imagNumber + c2->imagNumber;

	return sum;
}