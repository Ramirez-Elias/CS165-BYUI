/***********************************************************************
* Program:
* Assignment check02a
* Brother      , CS165
* Author:
* Elias Ramirez
* 
* Instructions:
*
* Write a C++ program according to the following:
*   1- Create a struct for a Student, that contains a string for a first 
*      name, a string for a last name, and an integer for an id.
*   2- Create a function called, displayStudent, that accepts a student 
*      struct, and displays their information in the following format: 
*     "id# - FirstName LastName".
* 
* The program should do the following:
*   1- Declare a Student struct called "user".
*   2- Prompt the user for their first name, last name, and id number, 
*      and save these values into your "user" struct.
*   3- Pass the user struct to the display function to be displayed.
* 
* Sample Output
* The following is an example of output for this program:
* Please enter your first name: Ashley
* Please enter your last name: Smith
* Please enter your id number: 12512
* 
* Your information:
* 12512 - Ashley Smith
* 
************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>

/***********************************************************************
* Struct Student
* Create a struct for a Student, that contains a string for a first name,
* a string for a last name, and an integer for an id.
************************************************************************/
struct Student
{
	std::string firstName = {};
	std::string lastName = {};
	int id = 0;
};


void displayStudent(Student * student);


/***********************************************************************
* MAIN:
************************************************************************/
int main()
{
	//Declare a Student struct called "user".
	Student student;

	//Prompt the user for their first name, last name, and id number, 
	//and save these values into your "user" struct.
	std::cout << "Please enter your fist name: ";
	std::cin >> student.firstName;
	std::cout << "Please enter your last name: ";
	std::cin >> student.lastName;
	std::cout << "Please enter your id number: ";
	std::cin >> student.id;

	Student *pStudent;
	pStudent = &student;
	displayStudent(pStudent);

	return 0;
}

/***********************************************************************
* displayStudent(Student * student)
* Create a function called, displayStudent, that accepts a student struct,
* and displays their information in the following format: 
* "id# - FirstName LastName".
************************************************************************/
void displayStudent(Student * student)
{
	std::cout << std::endl;
	std::cout << "Your information:\n"
		<< student->id << " - " << student->firstName << " "
		<< student->lastName << std::endl;

}