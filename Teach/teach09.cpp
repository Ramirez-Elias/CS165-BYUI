/***********************************************************************
* Program:
* Assignment teach09
* Brother      , CS165
* Author:
* Elias Ramirez
*
* Instructions:
* BYU-Idaho is having issues with their payroll system and has asked you
* to create a new one. You quickly recognize that there are two types of 
* employees, hourly employees (those that get paid a certain amount per 
* hour) and salary employees (those that receive an annual salary).
* While these two types of employees have differences, they also have a
* significant amount in common. So you decide to create a common base 
* class with each of these two types as a separate derived class.
* 
* For this assignment, you will start with a blank file. To keep our 
* focus directly on the virtual functions we are working with, you may
* put all of our classes in the same file rather than separate .h and 
* .cpp files.
************************************************************************/
#include <iostream>
#include <string>
using namespace std;

//Core Requirements 1: Create a base class Employee, and two derived 
// classes HourlyEmployee and SalaryEmployee, as follows:

// A- Employee should have a string name, a getter and setter for it,
//    and a display function that displays the name.
class Employee
{
public:
	Employee() {};
	~Employee() {};
	string getName();
	void setName(string name);
	virtual void display() { cout << getName(); }
protected:
	string name;
};

string Employee::getName()
{
	return this->name;
}

void Employee::setName(string name)
{
	this->name = name;
}

// B- HourlyEmployee should have an int hourlyWage (and getter/setter) and
//    should override the display function to the name and wage in the 
//    format: "John - $8/hour".
class HourlyEmployee : public Employee
{
public:
	HourlyEmployee() {};
	~HourlyEmployee() {};
	int getHourlyWage();
	void setHourlyWage(int hourlyWage);
	virtual void display();
private:
	int hourlyWage;
};

int HourlyEmployee::getHourlyWage()
{
	return this->hourlyWage;
}

void HourlyEmployee::setHourlyWage(int hourlyWage)
{
	this-> hourlyWage = hourlyWage;
}

void HourlyEmployee::display()
{
	cout << getName() << " - $" << getHourlyWage() << "/hour" << endl;
}

//C- SalaryEmployee should have an int salary (and getter/setter) and 
//   should override the display function to the name and salary in 
//   the format: "John - $50000/year".
class SalaryEmployee : public Employee
{
public:
	SalaryEmployee() {};
	~SalaryEmployee() {};
	int getSalary();
	void setSalary(int salary);
	virtual void display();
private:
	int salary;
};

int SalaryEmployee::getSalary()
{
	return this->salary;
}

void SalaryEmployee::setSalary(int salary)
{
	this->salary = salary;
}

void SalaryEmployee::display()
{
	cout << getName() << " - $" << getSalary() << "/year" << endl;
}
/***********************************************************
 * Function: Main
 * Prompts for a circle and displays it.
 ***********************************************************/
int main()
{
	//Core Requirements 2: Create a main function that does 
	// the following:
	
	//1. Declare an array for 3 employees.playground
	Employee * employees[3];
	char letter;
	string name("");
	int salary(0);
	//HourlyEmployee * hEmployee;
	//SalaryEmployee * sEmployee;

	//2- Loop through 3 times and prompt the user for an "h" (hourly employee) or
	//   an "s" (salary employee).
	//3- Then prompt for the name and the hourlyRate/salary
	//4- For each employee entered, create a new employee of the correct type 
	//   and add it to the array.
	for (int i = 0; i < 3; i++)
	{
		cout << "Please select h for hourly employee or s for salary employee: ";
		cin >> letter;
		if (letter == 'h')
		{
			HourlyEmployee * hEmployee;
			hEmployee = new HourlyEmployee;
	
			cout << "Name: ";
			cin.ignore();
			getline(cin, name);
			hEmployee->setName(name);
			cout << "Hourly Salary: ";
			cin >> salary;
			hEmployee->setHourlyWage(salary);
			employees[i] = hEmployee;
		}
		else
		{
			SalaryEmployee * sEmployee;
			sEmployee= new SalaryEmployee;
			cout << "Name: ";
			cin.ignore();
			getline(cin, name);
			sEmployee->setName(name);
			cout << "Yearly Salary: ";
			cin >> salary;
			sEmployee->setSalary(salary);
			employees[i] = sEmployee;

		}
		cout << endl;
	}
	cout << endl;
	for (int j = 0; j < 3; j++)
	{
		employees[j]->display();
	}

	for (int k = 0; k < 3; k++)
	{
		delete employees[k];
	}
	return 0;
}