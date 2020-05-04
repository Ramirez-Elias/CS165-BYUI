/***********************************************************************
* Program:
* Assignment teach07
* Brother      , CS165
* Author:
* Elias Ramirez
*
* Instructions:
* You will be provided with a skeleton ta07.cpp file that contains tests 
* for the program. As you complete each core requirement, remove the 
* comments necessary to test each section.
************************************************************************/
#include <iostream>
using namespace std;

// Core requirements
//2. Write a function, getValueFromPointer, that accepts a pointer to a
//   float and returns the actual floating point value. (A prototype is 
//   provided for you. You need to write the body of this function.)
float getValueFromPointer(float* thePointer);
float* getMinValue(float* a, float* b);

// Stretch goals
//2. A- Write a function that can swap two elements of the pointer array WITHOUT
//      modifying the original array of values.
void swapElements(float* theArray[], int a, int b);
void sortArray(float* theArray[]);

int main()
{
	
	//Core Requirement 1: Dynamically allocate an array of floats to store
	// the hexcopter propeller speed. Also make sure to delete this array 
	// at the end of the program. This means you should:
	cout << "**********************************************************************************\n";
	cout << "* Core Requirement 1                                                             *\n";
	cout << "**********************************************************************************\n";
	// A - Prompt for the number of floats (see provided code).
	int arraySize;
	cout << "Enter the array size: ";
	cin >> arraySize;

	//Stretch 1- Create an array of pointers to floats and set it to point to
	//each item in the original array, and display them. This means you need to:

	//Stretch 1 - A: Dynamically allocate an array of float pointers.
	float **pointerArray = new float*[arraySize];
	float * pHolder;
	//B- Dynamically allocate an array of floats: Allocate your array(s) here
	float * pPropSpeed = new float[arraySize];
	// Fill your array with float values
	//C - Prompt the user for floats to fill up the array.
	for (int i(0); i < arraySize; i++)
	{
		cout << "Enter a float value: ";
		cin >> pPropSpeed[i];
		//Strecht 1 - B:Loop through your original array and put a pointer to each
		// of those items into your new array. In other words, spot 0 in the pointer 
		// array should have a pointer to spot 0 in the original array, and so forth.
		//pointerArray[i] = pPropSpeed[i];
		pHolder =  &pPropSpeed[i];
		pointerArray[i] = pHolder;

	}

	// Core Requirement 2
	cout << endl;
	cout << "**********************************************************************************\n";
	cout << "* Core Requirement 2 - Display Value from Pointer Function                       *\n";
	cout << "**********************************************************************************\n";
	for (int i(0); i < arraySize; i++)
	{
		float value = getValueFromPointer(pPropSpeed + i);
		cout << "The value of the element " << i << " is: ";
		cout << value << endl;
	}
	// Core Requirement 3
	cout << endl;
	cout << "**********************************************************************************\n";
	cout << "* Core Requirement 3 - Show Smallest Value from First and Last Element           *\n";
	cout << "**********************************************************************************\n";
	// Print the smaller of the first and last elements of the array
	float * minValue = getMinValue(&pPropSpeed[0], &pPropSpeed[arraySize - 1]);
	cout << "Smallest Number: " << *minValue << endl;
	
	
	
	// Strecht Challenge 2
	cout << endl;
	cout << "**********************************************************************************\n";
	cout << "* Stretch Challenge 1 - Dinamic Allocation                                       *\n";
	cout << "**********************************************************************************\n";
	for (int i(0); i < arraySize; i++)
	{
		float value = getValueFromPointer(pPropSpeed + i);
		cout << "Value of Original Array's Element " << i << " is: ";
		cout << value << endl;

		//Strecht 1 - C: Next, loop through the items in your pointer array, and use
		//the pointer to get the value and display it.
		cout << "Value for Pointer Array's Element " << i << " is: "
			<< *pointerArray[i] << " and the Address is: " << pointerArray[i] << endl;
	}

	cout << endl;
	cout << "**********************************************************************************\n";
	cout << "* Stretch Challange 2 - Swap values from First and Last Element                  *\n";
	cout << "**********************************************************************************\n";
	//Stretch 2 - Write a function to swap elements of the pointer array, swap the first
	// and last values, and display them. This means you need to do the following:
	swapElements(pointerArray, 0, (arraySize-1));
	for (int i(0); i < arraySize; i++)
	{
		//Stretch 2 - C: Loop through the original array of values, display them, and ensure they 
		//               have not changed.
		float value = getValueFromPointer(pPropSpeed + i);
		cout << "The value of the original array element " << i << " is: ";
		cout << value << endl;

		//Stretch 2 - D: Loop through the array of pointers and use the pointers to display the values and ensure
		//				 that the first and last are in a different order.
		cout << "The value of the pointer array element " << i << " is: ";
		cout << *pointerArray[i] << endl;
	}
	// D - Delete the array at the end of main.
	delete[] pPropSpeed;
	delete[] pointerArray;
	return 0;
}

float getValueFromPointer(float* thePointer)
{
	return *thePointer;
}

float* getMinValue(float* a, float* b)
{
	if (a < b) 
	{
		return a;
	}
	else
	{
		return b;
	}
}

//Stretch 2 - A: Write a function that can swap two elements of the pointer array WITHOUT
//               modifying the original array of values.
//            B: Use this function to swap the first and last elements of the pointer array.
void swapElements(float* theArray[], int a, int b)
{
	float *p1 = theArray[a];
	theArray[a] = theArray[b];
	theArray[b] = p1;
}
