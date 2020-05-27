/***********************************************************************
* Program:
*    Checkpoint 10b, Removing from Vectors
*    Brother      , CS165
* Author:
* Elias Ramirez
*
* This checkpoint is intended to help you practice the syntax of removing
* from vectors.
* Consider that you are writing a program to track your food storage 
* inventory. Each item in your inventory has a name and an expiration
* date. At some point, you realize that you have a lot of food that has
* expired and you want to remove it from your inventory list
*
* For this assignment, you can do all of your work in a single .cpp file 
* for simplicity. Recognize that much of the code (regarding the the Food 
* class, etc.) has been provided. Your task is to concentrate on adding 
* and removing from a vector.
************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/***********************************************************
 * Class: Food
 * Description: Holds a food name composed of a name and its
 *   expiration date.
 *
 * You do not need to change this class.
 ***********************************************************/
class Food
{
private:
	string name;
	int month;
	int year;

public:
	/***********************
	 * Constructors
	 ***********************/
	Food()
	{
		name = "Unspecified";
		month = -1;
		year = -1;
	}

	Food(string name, int month, int year)
	{
		this->name = name;
		this->month = month;
		this->year = year;
	}

	~Food()
	{
		cout << "Deleting " << name << endl;
	}

	/***********************
	 * Getters/Setters
	 ***********************/
	string getName() const { return name; }
	int getMonth() const { return month; }
	int getYear() const { return year; }

	void setName(string name) { this->name = name; }
	void setMonth(int month) { this->month = month; }
	void setYear(int year) { this->year = year; }

	/***********************
	 * Display
	 ***********************/
	void display() const
	{
		cout << name << " - " << month << "/" << year << endl;
	}
};

/*****************************************************
 * Function: promptInventory
 * Description: Asks the user for each item in their
 *   inventory and adds them to the vector.
 *****************************************************/
void promptInventory(vector<Food*> &items)
{
	string name;
	int month;
	int year;

	//3. First, the provided code calls a function 
	//   promptInventory. This function will prompt the user
	//   for new food items until they enter quit. These 
	//   values (the name, month, and year) are stored in 
	//   simple local variables for you to use.
	do
	{
		cout << "Enter item name: ";
		getline(cin, name);

		if (name != "quit")
		{
			cout << "Enter expiration month: ";
			cin >> month;

			cout << "Enter expiration year: ";
			cin >> year;

			cin.ignore(); // get rid of the extra '\n' char


			// TODO: Fill this in!

			//4- Fill in the body of the loop in the promptInventory 
			//   function to create a new Food object, populate it 
			//   with the correct values, and add it to the vector.
			Food * food = new Food;
			food->setName(name);
			food->setMonth(month);
			food->setYear(year);
			items.push_back(food);
			cout << endl;
		}


	} while (name != "quit");
}


/*****************************************************
 * Function: displayInventory
 * Description: Displays each item in the inventory
 *****************************************************/
void displayInventory(vector<Food*> &items)
{
	cout << "Your current inventory:\n";


	// TODO: Fill this in!

	//5- When the user is done entering food, your program will call 
	//   the function, displayInventory to display each item. You need 
	//   to fill in the body of this function to use an iterator to go 
	//   through each item in the vector and display it.
	for (vector <Food*>::iterator it = items.begin(); it != items.end(); ++it)
	{
		(*it)->display();
	}

}

/*****************************************************
 * Function: removeExpiredItems
 * Description: Removes any items that have expired
 *  (occurred before the given month and year) and
 *  deletes them.
 *****************************************************/
void removeExpiredItems(vector<Food*> &items, int currentMonth,
	int currentYear)
{
	cout << "Checking for expired items...\n";


	// TODO: Fill this in!
	//7- It then calls the function removeExpiredItems to remove 
	//   the food from the list that has expired. You need to 
	//   fill in the body of this function.
	vector <Food*>::iterator it;
	for(it = items.begin(); it != items.end(); )
	{
		if ((*it)->getMonth() < currentMonth && (*it)->getYear() <= currentYear)
		{
			Food* pFood = *it;
			delete pFood;
			pFood = NULL;
			it = items.erase(it);
		}
		else
			it++;
	}

}

/*****************************************************
 * Function: removeExpiredItems
 * Description: Removes any items that have expired
 *  (occurred before the given month and year) and
 *  deletes them.
 *****************************************************/
void deleteRemainingItems(vector<Food*> &items)
{
	cout << "Cleaning up remaining items...\n";

	// You don't need to change this one--it works already.
	// (You can use it as a hint for your above functions...)

	vector<Food*>::iterator it = items.begin();

	while (it != items.end())
	{
		// *it (or in other words the thing that it refers to) is a Food*
		// so that's the thing we want to delete.
		Food* pFood = *it;
		delete pFood;

		// Not required, but its good to set pointers to null after deleting
		pFood = NULL;

		it = items.erase(it);

		// we don't need to call it++ in this case because erasing the
		// current item will automatically advance it to the next one.
	}

}

int main()
{
	vector<Food*> items;

	promptInventory(items);
	cout << endl;

	displayInventory(items);
	cout << endl;

	int month;
	int year;

	cout << "Enter current month: ";
	cin >> month;

	cout << "Enter current year: ";
	cin >> year;
	cout << endl;

	removeExpiredItems(items, month, year);
	cout << endl;

	displayInventory(items);
	cout << endl;

	deleteRemainingItems(items);

	cout << "\nGoodbye\n";

	return 0;
}