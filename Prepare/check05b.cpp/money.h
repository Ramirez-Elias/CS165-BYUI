/******************
 * File: money.h
 ******************/
#ifndef MONEY_H
#define MONEY_H


//4. Add the following constructors :
//   Default - Set the values to 0.
//   Non - default that accepts 1 integer - Sets the dollar amount to that integer, sets the cents to 0.
//   Non - default that accepts 2 integers - Sets the dollar amount to the first, and the cents to the second.

class Money
{
public:
	Money() :dollars(0) , cents(0) { }//   Default - Set the values to 0.
	Money(int dollars);//   Non - default that accepts 1 integer - Sets the dollar amount to that integer, sets the cents to 0.
	Money(int dollars, int cents);//  Non - default that accepts 2 integers - Sets the dollar amount to the first, and the cents to the second.
	~Money(){}
	int getDollars() const;
	void setDollars(int dollars);
	int getCents() const;
	void setCents(int cents);
	//4- This class has simple prompt and display methods that expect 
	//   these getters and setters to be present.
	void prompt();
	void display() const;
private:
	int dollars;
	int cents;
};


#endif