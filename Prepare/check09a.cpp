/***********************************************************************
* Program:
*    Checkpoint 09a, Virtual Functions
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
#include <string>
using namespace std;

// For this assignment, for simplicity, you may put all of your classes
// in this file.

// TODO: Define your classes here

//2. Create a class for a Car that has the following member variables and 
//    methods as described above:
// #name : string, +getName() : string, + setName(string) : void, + getDoorSpecs() : string
class Car
{
public:
	//3- In the constructor, set the name variable to be "Unknown model".
	Car() : name("Unknown model") {};
	~Car() {};
	string getName();
	void setName(string name);
	//3- Fill in a default getDoorSpecs() method that returns the string "Unknown doors".
	virtual string getDoorSpecs() { return "Unknown doors"; }
protected:
	string name;
};

string Car::getName()
{
	return this->name;
}

void Car::setName(string name)
{
	this->name = name;
}


//4- Next create a class Civic that inherits from the Car class and overrides the 
//    getDoorSpecs() to return the string "4 doors". In the constructor, set the 
//    name variable to be "Civic".

class Civic : public Car
{
public:
	Civic() { this->name = "Civic"; }
	~Civic() {};
	virtual string getDoorSpecs() { return "4 doors"; }
private:

};

//5 - Next create a class Odyssey that inherits from the Car class and overrides 
//    the getDoorSpecs() to return the string "2 front doors, 2 sliding doors, 
//    1 tail gate".In the constructor, set the name variable to be "Odyssey".

class Odyssey : public Car
{
public:
	Odyssey() { this->name = "Odyssey"; }
	~Odyssey() {};
	virtual string getDoorSpecs() { return "2 front doors, 2 sliding doors, 1 tail gate"; }
private:

};


//6- Next create a class Ferrari that inherits from the Car class and overrides the
//   getDoorSpecs() to return the string "2 butterfly doors".In the constructor, 
//   set the name variable to be "Ferrari".
class Ferrari : public Car
{
public:
	Ferrari() { setName("Ferrari"); };
	~Ferrari() {};
	virtual string getDoorSpecs() { return "2 butterfly doors"; }
private:

};

/**********************************************************************
 * Function: attachDoors
 * Purpose: This function can accept any type of Car object. It will
 *  call the appropriate functions to display the name and the doors info.
 ***********************************************************************/

 // TODO: Include your attachDoors function here

//7- A main function is provided that creates one of each of these cars, 
//   and passes it to a method called "attachDoors". You need to write this
//   method. It should accept any type of car and display the text: 
//   "Attaching doors to Civic - 4 doors" (Of course, replacing "Civic" with
//   the appropriate name, and "4 doors" with the result of calling the 
//   getDoorSpecs() method).
void attachDoors(Car &car)
{
	cout << "Attaching doors to " << car.getName() << " - " << car.getDoorSpecs() << endl;
}

 /**********************************************************************
  * Function: main
  * Purpose: This is the entry point and driver for the program.
  ***********************************************************************/
int main()
{
	// You should not change main

	Civic civic;
	Odyssey odyssey;
	Ferrari ferrari;

	attachDoors(civic);
	attachDoors(odyssey);
	attachDoors(ferrari);

	return 0;
}
