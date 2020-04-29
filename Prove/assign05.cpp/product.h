
/***************************************************************
 * File: product.h
 * Author: Elias Ramirez
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream> // console in/out statements (cin/cout)
#include <iomanip>  // we will use setw() in this example
#include <string>   // to use string class



class Product
{
public:
	//Default Constructor - Set the name to "none", description to "",
	//and the weight and the base price to 0.
	Product() : name("none"), description(""), weight(0), basePrice(0) {}
	Product(std::string name, std::string description, int basePrice, int weight);
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
	//4- Add the following to your Product class:
	//   getName / setName - getDescription / setDescription
	//   getBasePrice / setBasePrice - getWeight / setWeight
	std::string getName();
	void setName(std::string name);
	std::string getDescription();
	void setDescription(std::string description);
	int getBasePrice();
	void setBasePrice(int basePrice);
	int getWeight();
	void setWeight(int weight);
		
private:
	std::string name;
	float basePrice;
	float weight;
	std::string description;
};




#endif
