/***********************************************************************
* Program:
* Assignment check03b
* Brother      , CS165
* Author:
* Elias Ramirez
*
* Write a C++ program that prompts the user for a number, but if the user
* enters a word instead, the program handles it gracefully and re-prompts
* for a number 
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
	// 4 - Continue reprompting as long as the input is invalid.
	bool invalid(false);
	do
	{
		try
		{
			// 2 - Have main call this function and then display the result.
			int number = prompt();
			std::cout << "The number is " << number << std::endl;
			invalid = false;

		}
		//If the exception is thrown. Main should display: "Error: " followed
		//by the content of the exception message that was caught. It should 
		//not try display the number returned from the prompt function in this case.
		catch (const std::string message)
		{
			std::cout << "Error: " << message << std::endl;
			//3D - Then, reprompt for the number.
			invalid = true;
		}
	} while (invalid);
	return 0;
}

/***********************************************************************
* prompt()
* 1- Write a function, prompt, that prompts the user for a number, and
* returns it.
* 3 - In the prompt function, check for invalid input 
* (i.e., cin.fail()). If a failure condition occurs:
************************************************************************/
int prompt() throw (std::string)
{
	int number(0);

		std::cout << "Enter a number: ";
		std::cin >> number;
		//check for invalid input (i.e., cin.fail())
		if (std::cin.fail())
		{
			//3A - Clear the fail status.
			std::cin.clear();
			//3B - Ignore the rest of the input in the buffer.
			std::cin.ignore(256, '\n');
			//3C - Display the message: "Invalid input."
			throw std::string("Invalid input.");
		}
	return number;
}
