/***************************************************************
 * File: order.cpp
 * Author: Elias Ramirez
 * Purpose: Contains the method implementations for the order 
 * class.
 ***************************************************************/
#include "order.h"

Order::Order(Product product, int quantity, Customer customer)
{
	this->product = product;
	this->quantity = quantity;
	this->customer = customer;
}

Product Order::getProduct()
{
	return this->product;
}

void Order::setProduct(Product Product)
{
	this->product = product;
}

int Order::getQuantity()
{
	return this->quantity;
}

void Order::setQuantity(int quantity)
{
	this->quantity=quantity;
}

Customer Order::getCustomer()
{
	return this->customer;
}

void Order::setCustomer(Customer customer)
{
	this->customer = customer;
}

string Order::getShippingZip() // - Returns the Zip from the customer's address
{
	return this->customer.getAddress().getZip();
}

float Order::getTotalPrice() //  - Returns the total price of the product(including tax and shipping) multiplied by the quantity.
{
	return ((this->product.getTotalPrice()) * (this->quantity));
}

void Order::displayShippingLabel() //  - Calls the customer's display method, resulting in this format:
{
	this->customer.display();
}

void Order::displayInformation() //-Displays the customer's name, the product's name, and the total price of the order in this format(substituting for the correct values) :
{
	cout << this->customer.getName() << endl;
	cout << this->product.getName() << endl;
	cout << "Total Price: $" << getTotalPrice();
}