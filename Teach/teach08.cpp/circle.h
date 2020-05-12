#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include "point.h"
using namespace std;

// 1- Create the basic Circle class as follows:
//    1A- Create a Circle class that inherits from, or extends,
//        the Point class.
//    1B- You should create both a circle.h and circle.cpp file. 
//        The makefile will look for and build files with these names. 
//        (Don't forget the #ifndef lines in your .h file)

class Circle : public Point
{
public:
	//1C- Add a radius to your class and a getter and setter for it.
	void setRadius(float radius);
	float getRadius();
	//1D- Create a blank method for promptForCircle and display.
	void promptForCircle();
	void display();
private:
	float radius;
};



#endif