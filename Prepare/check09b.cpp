/***********************************************************************
* Program:
*    Checkpoint 09a, Pure Virtual Functions
* Brother      , CS165
* Author:
* Elias Ramirez
*
*  For this assignment, because the classes we are going to create are so
*  small and simplistic, and to help you focus on just the elements of 
*  inheritance, rather than the mechanics of creating lots of files, you 
*  will put all of your classes at the top of the main file, rather than
*  creating separate .h and .cpp files like we would for larger, 
*  real-world classes.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// For this assignment, for simplicity, you may put all of your classes
// in this file.

class Shape
{
private:
	string name;

public:
	virtual ~Shape() { }
	string getName() const { return name; }
	void setName(string name) { this->name = name; }

	// TODO: Define your pure virtual function here

	//2- A Shape class has been provided that has a name with its getter
	//   and setter. You need to add a pure virtual function getArea()

	virtual float getArea() = 0;
};

// 3- A Circle class has been provided with a radius, its getter/setter 
//    and a destructor. You need to add the following:
//    1. Add a Circle constructor, and in it set the name variable to be "Circle".
//    2. Redefine the getArea() method to return "3.14 * radius * radius".
class Circle : public Shape
{
private:
	float radius;

public:
	~Circle()
	{
		cout << "Cleaning up " << getName() << endl;
	}

	float getRadius() const { return radius; }
	void setRadius(float radius) { this->radius = radius; }

	// TODO: Implement a constructor here
	Circle()
	{
		setName("Circle");
	}
	// TODO: Redefine getArea() here
	virtual float getArea() { return 3.14 * this->radius * this->radius; }
};

//4- A Rectangle class has been provided with a length and width, their 
//   getters/setters and a destructor. You need to add the following
//   1. Add a Rectangle constructor, and in it set the name variable to be "Rectangle".
//   2. Redefine the getArea() method to return "length * width".
class Rectangle : public Shape
{
private:
	float length;
	float width;

public:
	~Rectangle()
	{
		cout << "Cleaning up " << getName() << endl;
	}

	float getLength() const { return length; }
	float getWidth() const { return width; }
	void setLength(float length) { this->length = length; }
	void setWidth(float width) { this->width = width; }

	// TODO: Implement a constructor here
	Rectangle()
	{
		setName("Rectangle");
	}
	// TODO: Redefine getArea() here
	virtual float getArea() { return this->length * this->width; }
};

const int MAX_SIZE = 10;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
	// We will put all of our code in main for this one, just to keep
	// the focus on the virtual functions and not on passing items
	// between functions.
	
	//5- The provided code supplies you with a main function. It takes care
	//   of prompting the user for the correct values, and looping through.
	//   You need to add the following to main (at the places indicated in 
	//   the comments): 

	// TODO: 1. Declare your array here
	// For this assignment you can use the size: MAX_SIZE
	Shape* shapeArray[MAX_SIZE];

	char letter;
	int count = 0;

	do
	{
		cout << "Please enter 'c' for circle, 'r' for rectangle or 'q' to quit: ";
		cin >> letter;

		if (letter == 'c')
		{
			float radius;
			cout << "Enter the radius: ";
			cin >> radius;

			// TODO: 2. Create your circle object here, set the radius value
			// and add it to the array at index "count".
			Circle * circle = new Circle;
			circle->setRadius(radius);
			shapeArray[count] = circle;

			count++; // we have seen another shape
		}
		else if (letter == 'r')
		{
			float length;
			float width;

			cout << "Enter the length: ";
			cin >> length;

			cout << "Enter the width: ";
			cin >> width;

			// TODO: 3. Create your rectangle object here, set the length and
			// width, and add it to the array at index "count".
			Rectangle * rectangle = new Rectangle;
			rectangle->setLength(length);
			rectangle->setWidth(width);
			shapeArray[count] = rectangle;

			count++; // we have seen another shape
		}

	} while (letter != 'q');

	// Set the precision for our decimals
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// Now we will display each shape
	for (int i = 0; i < count; i++)
	{
		// TODO: 4. Add a cout statment here to display the name and the area
		// of each shape in the list in the format "Circle - 10.32"
		cout << shapeArray[i]->getName() << " - " << shapeArray[i]->getArea() << endl;
		
	}

	// TODO: 5. Loop through and free the memory of each object.
	for (int j = 0; j < count; j++)
	{

		delete shapeArray[j]; 

	}


	return 0;
}