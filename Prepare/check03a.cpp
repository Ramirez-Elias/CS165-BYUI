/***********************************************************************
* Program:
* Assignment check03a
* Brother      , CS165
* Author:
* Elias Ramirez
*
* Write a C++ program that prompts the user for a positive even number,
* less than 100. If the user enters a number that is not valid, an 
* exception message should be thrown from one function, caught in another
* and displayed to the user. 
************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>

//Prototyping
int prompt() throw (std::string);

/***********************************************************************
* MAIN:
************************************************************************/
int main()
{
	// 4 - Set up main to try the function, and catch a potential 
	//exception.
	try
	{
		// 2 - Have main call this function and then display the result.
		int number = prompt();
		std::cout << "The number is " << number << std::endl;

	}
	//If the exception is thrown. Main should display: "Error: " followed
	//by the content of the exception message that was caught. It should 
	//not try display the number returned from the prompt function in this case.
	catch (const std::string message)
	{
		std::cout << "Error: " << message << std::endl;
	}

	return 0;
}

/***********************************************************************
* prompt()
* 1- Write a function, prompt, that prompts the user for a number, and
* returns it.
* 3 -In the prompt function, after getting the number from the user, 
* the program should check for the following conditions (in this order)
* and throw a string with the accompanying message:
************************************************************************/
int prompt() throw (std::string)
{
	int number(0);
	std::cout << "Enter a number: ";
	std::cin >> number;
	//3A - Condition: Number is less than 0. Message: "The number cannot
	//be negative."
		if (number < 0)
			//If you are trying to catch a string, you must throw a string, 
			//which could be done like so: throw string("message here");.
			throw std::string("The number cannot be negative.");

		//3B - Condition: Number is greater than 100. Message: "The number
		//cannot be greater than 100."
		else if (number > 100)
			//If you are trying to catch a string, you must throw a string, 
			//which could be done like so: throw string("message here");.
			throw std::string("The number cannot be greater than 100.");

		//3C - Condition: Number is odd. Message: "The number cannot be odd."
		else if (number % 2 != 0)
			//If you are trying to catch a string, you must throw a string, 
			//which could be done like so: throw string("message here");.
			throw std::string("The number cannot be odd.");


	return number;
}
