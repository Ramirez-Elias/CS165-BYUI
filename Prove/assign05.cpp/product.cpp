/***************************************************************
 * File: product.cpp
 * Author: Elias Ramirez
 * Purpose: Contains the method implementations for the Product 
 * class.
 ***************************************************************/
#include "product.h"



//Non - default - Accepts all four of these values(name, 
//  description, basePrice, weight) and sets them.
Product::Product(std::string name, std::string description, int basePrice, int weight)
{
	this->name = name;
	this->description = description;
	this->basePrice = basePrice;
	this->weight = weight;

}


//2- Create a prompt method (function) that prompts for the name, 
//   base price, weight, and description, and sets these values in 
//   the current object.
void Product::prompt()
{
	//Your prompt function should reprompt for the price if text 
	//or a number less than 0 is provided.
	bool isZero(false);

	do
	{
		if (isZero) { isZero = false; }
		std::cout << "Enter name: ";
		std::getline(std::cin, name);
		if (name == "")
		{
			isZero = true;
			std::cin.clear();
		}
	}while (isZero);
	
	do
	{
		if (isZero) { isZero = false; }
		std::cout << "Enter description: ";
		std::getline(std::cin, description);
		if (description == "")
		{
			isZero = true;
			std::cin.clear();
		}
	} while (isZero);
	
	do
	{
		if (isZero) { isZero = false; }
		std::cout << "Enter weight: ";
		std::cin >> weight;
		if (weight == 0)
		{
			isZero = true;
			std::cin.ignore();
		}
	}while (isZero);
	
	do
	{
		if (isZero) { isZero = false; }
		std::cout << "Enter price: ";
		std::cin >> basePrice; 
		if (basePrice == 0)
			isZero = true;
	}while (isZero);
	
}

//3- Create a getSalesTax method to that returns 6% of the base price.
float Product::getSalesTax()
{
	return basePrice * 0.06;
}

//4- Create a getShippingCost method that returns a flat rate of $2.00
//   if the item is less than 5 lbs, and $2.00 + $0.10 per pound over 5 lbs.
float Product::getShippingCost()
{
	float flatRate(2);
	if (weight <= 5)
		return flatRate;
	else
		return (weight - 5) * 0.10;
}

//5- Create a getTotalPrice method that uses your other methods to return a
//   total price.
float Product::getTotalPrice()
{
	return basePrice + getSalesTax() + getShippingCost();

}

//6- Create three display methods to display the data in each of the 
//   following formats:

//6A- Advertising Profile: Should display the name, base price, 
// and description in this format
void Product::displayAdvertising()
{
	std::cout << name << " - $" << basePrice << std::endl;
	std::cout << "(" << description << ")\n";

}

//6B- Inventory Line Item: Should display the base price, name, and 
//weight in this format:
void Product::displayInventory()
{
	std::cout << "$" << basePrice << " - " << description << " - ";
	std::cout.precision(1);
	std::cout << weight << " lbs" << std::endl;
}

//6C- Receipt: Should display the name, base price, sales tax, shipping cost,
//    and total price, in this format
void Product::displayReceipt()
{
	std::cout << name << std::endl;
	std::cout << "Price:         $" << std::setw(8) << basePrice << std::endl;
	std::cout << "Sales tax:     $" << std::setw(8) << getSalesTax() << std::endl;
	std::cout << "Shipping cost: $" << std::setw(8) << getShippingCost() << std::endl;
	std::cout << "Price:         $" << std::setw(8) << getTotalPrice() << std::endl;
}

std::string Product::getName()
{
	return this->name;
}

void Product::setName(std::string name)
{
	this->name = name;
}

std::string Product::getDescription()
{
	return this->description;
}

void Product::setDescription(std::string description)
{
	this->description = description;
}

int Product::getBasePrice()
{
	return this->basePrice;
}

void Product::setBasePrice(int basePrice)
{
	this->basePrice = basePrice;
}

int Product::getWeight()
{
	return this->weight;
}

void Product::setWeight(int weight)
{
	this->weight = weight;
}