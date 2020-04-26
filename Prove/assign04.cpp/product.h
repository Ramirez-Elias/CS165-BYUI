
/***************************************************************
 * File: product.h
 * Author: 
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream> // console in/out statements (cin/cout)
#include <iomanip>  // we will use setw() in this example
#include <string>   // to use string class

// put your class definition here
// product details and methods

//1- Create a class for a product that stores the name, base price,
//weight, and description of a product.
class Product
{
public:
	//2- Create a prompt function
	void prompt();
	//3- Create a getSalesTax method
	float getSalesTax();
	//4- Create a getShippingCost method
	float getShippingCost();
	//5- Create a getTotalPrice method 
	float getTotalPrice();
	//6- Create three display methods
	void displayAdvertising();
	void displayInventory();
	void displayReceipt();

private:
	std::string name;
	float basePrice;
	float weight;
	std::string description;
};




#endif
