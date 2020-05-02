/****************************
 * File: icecream.h
 ****************************/
#ifndef ICECREAM_H
#define ICECREAM_H

#include <string>

class IceCream
{
private:
	std::string flavor;
	float price;

public:
	IceCream();
	IceCream(std::string flavor, float price);
	float getTotalPrice() const;
	void prompt();
	void display() const;

	//3- Add to this class a public static variable named salesTax.
	static float salesTax;
};


#endif