/***********************************************************************
* Program:
*    Checkpoint 10a, Vectors
*    Brother      , CS165
* Author:
* Elias Ramirez
*
*  For this assignment, you will create two vectors, one a vector of ints
*  and one a vector of strings. The user will fill each one with data, 
*  and then your program will display the values.
*  
*  For this assignment, in order to focus our practice on the syntax of 
*  the vectors, you can put all of your code in main.
************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;



/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{

	//3- Create and display a vector of ints as follows :

	//3.1- Create a vector of ints.
	vector <int> intsVector;

	//3.2- Prompt the user for ints until they enter 0, and store them 
	//     in your vector.
	int number(1);
	do
	{
		cout << "Enter int: ";
		cin >> number;
		if(number!= 0)
			intsVector.push_back(number);
	} while (number != 0);
	
	//3.3- Loop through all the numbers in the vector and display each one.
	cout << "Your list is:\n";
	//3.4- When you loop through, make sure to use the size of your vector in your
	//     condition (not a separate integer from above).
	for (int i(0); i < intsVector.size(); i++)
	{
		cout << intsVector[i] << endl;
	}

	cout << endl;

	//4- Create and display a vector of strings as follows :

	//4.1- Create a vector of strings.
	vector <string> stringsVector;

	//4.2- Prompt the user for strings until they enter "quit",  
	//     and store them in your vector.
	string sHolder("");
	do
	{
		cout << "Enter string: ";
		cin >> sHolder;
		if (sHolder != "quit")
			stringsVector.push_back(sHolder);
	} while (sHolder != "quit");

	//4.3- Loop through all the numbers in the vector and display each one.
	cout << "Your list is:\n";
	//4.4- When you loop through, make sure to use the size of your vector in your
	//     condition (not a separate integer from above).
	for (int i(0); i < stringsVector.size(); i++)
	{
		cout << stringsVector[i] << endl;
	}
	return 0;
}
