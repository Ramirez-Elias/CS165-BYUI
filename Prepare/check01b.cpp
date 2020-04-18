/***********************************************************************
* Program:
* Assignment check01b
* Brother      , CS165
* Author:
* Elias Ramirez
* 
* Instructions:
* Write a function, getSize, that prompts for the size of the list, or 
* the number of integers to be read in.
* Write a function, getList, that accepts an array of integers and a 
* count. It should prompt the user for the list of numbers and store 
* them in the passed array.
* Write a function, displayMultiples that accepts the array and its size.
* It should loop through each element in the array and display it if it 
* is divisible by 3.
* 
* Sample Output
* You may assume that the size of the list will always be less than 20.
* The following is an example of output for this program:
* Enter the size of the list: 5
* Enter number for index 0: 2
* Enter number for index 1: 3
* Enter number for index 2: 4
* Enter number for index 3: 5
* Enter number for index 4: 6
*
* The following are divisible by 3:
* 3
* 6
************************************************************************/
#include <iostream>
#include <string>
using namespace std;
#define SIZE 9
//Prototyping
int getSize();
void getList(int list[], int count);
void displayMultiples(int list[], int size);

/***********************************************************************
* MAIN:
************************************************************************/
int main()
{
	int count = getSize();
	int list[SIZE];
	getList(list, count);
	displayMultiples(list, count);
	return 0;
}

/***********************************************************************
* getSize()
* Write a function, getSize, that prompts for the size of the list, or
* the number of integers to be read in.
************************************************************************/
int getSize()
{
	int size;
	//ask for size
	cout << "Enter the sizeof the list: ";
	cin >> size;
	return size;
}

/***********************************************************************
* getList(int list[], int count)
* Write a function, getList, that accepts an array of integers and a 
* count. It should prompt the user for the list of numbers and store 
* them in the passed array
************************************************************************/
void getList(int list[], int count)
{
	for (int i(0); i < count; i++)
	{
		//ask for index number
		cout << "Enter number for index " << i << ": ";
		cin >> list[i];
	}
}

/***********************************************************************
* displayMultiples(int list[], int size)
* Write a function, displayMultiples that accepts the array and its size.
* It should loop through each element in the array and display it if it 
* is divisible by 3.
************************************************************************/
void displayMultiples(int list[], int count)
{
	//list to be displayed created
	int multipleList[SIZE];
	int counter(0);
	//check if divisible by 3
	for (int i(0); i < count; i++)
	{
		//if multiple
		if (list[i] % 3 == 0)
		{
			//the copy the result into the multiple list
			multipleList[counter] = list[i];
			counter++;
		}
	}
	//display result
	cout << "The following are divisible by 3:\n";
	for (int j(0); j < counter; j++)
	{
		cout << multipleList[j] << endl;
	}
}