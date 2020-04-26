/***********************************************************************
* Program:
* Assignment Assign04 - ECOMMERCE PRODUCT INVENTORY
* Brother      , CS165
* Author:
* Elias Ramirez
*
* This week, you will create our own library to handle products: to store
* their information, compute shipping costs, and display receipts, etc. 
* Next week you will build on this by adding additional functionality..
************************************************************************/
#include "product.h"
#include <iostream>


/***********************************************************************
* MAIN:
* 8- Create a main function that creates a new Product, calls its prompt 
*    method. Then have main prompt the user for which kind of display to
*    see (advertising profile, an inventory line item, or a receipt for 
*    this product) and call the appropriate method.
************************************************************************/
int main()
{
	//Dollar amounts should be shown to 2 decimal places, and weights 
	//should be shown to 1 decimal place. This can be done using the 
	//following code (and include the iomanip library):
	std::cout.setf(std::ios::fixed);
	std::cout.setf(std::ios::showpoint);
	std::cout.precision(2);

	// Declare your Product object here
	Product product;
	// Call your prompt function here
	product.prompt();

	std::cout << std::endl;
	std::cout << "Choose from the following options:\n";
	std::cout << "1 - Advertising profile\n";
	std::cout << "2 - Inventory line item\n";
	std::cout << "3 - Receipt\n";
	std::cout << std::endl;
	std::cout << "Enter the option that you would like displayed: ";

	int choice;
	std::cin >> choice;

	std::cout << std::endl;

	if (choice == 1)
	{
		// Call your display advertising profile function here
		product.displayAdvertising();
	}
	else if (choice == 2)
	{
		// Call your display inventory line item function here
		product.displayInventory();
	return 0;
	}
	else
	{
		// Call your display receipt function here
		product.displayReceipt();
	}

	return 0;
}