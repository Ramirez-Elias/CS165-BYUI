/***************************************************************
 * File: order.h
 * Author: Elias Ramirez
 * Purpose: Contains the definition of the Order class
 ***************************************************************/
#ifndef ORDER_H
#define ORDER_H
#include"product.h"
#include "customer.h"
#include <iostream>
#include <string>
using namespace std;

//5- Create a class for an Order that has the following private 
//   data members : 
//     product: Product - quantity : int - customer : Customer

class Order
{
public:
	//Default - Set the quantity to 0 and uses the product and 
	//customer's default constructors.
	Order(): quantity(0), product(), customer() {};
	//Non - default - Accepts a Product, quantity, and Customer
	Order(Product product, int quantity, Customer customer);
	~Order() {}
	//It should also contain the following public methods:
	Product getProduct(); 
	void setProduct(Product Product);
	int getQuantity();  
	void setQuantity(int quantity);
	Customer getCustomer();
	void setCustomer(Customer customer);
	string getShippingZip(); // - Returns the Zip from the customer's address
	float getTotalPrice(); //  - Returns the total price of the product(including tax and shipping) multiplied by the quantity.
	void displayShippingLabel(); //  - Calls the customer's display method, resulting in this format:
	void displayInformation(); //-Displays the customer's name, the product's name, and the total price of the order in this format(substituting for the correct values) :

private:
	Product product; 
	Customer customer;
	int quantity;
};


#endif
