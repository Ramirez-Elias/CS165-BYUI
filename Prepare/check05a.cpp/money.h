/******************
 * File: money.h
 ******************/
#ifndef MONEY_H
#define MONEY_H


// 2- Please note that this code does not compile at this
//     point. You need to add code to make it compile.

//3- Add the following member functions :
//   getDollars - getCents - setDollars - setCents

class Money
{
public:
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