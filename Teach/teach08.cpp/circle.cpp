#include "circle.h"

void Circle::setRadius(float radius)
{
	this->radius = radius;
}

 float Circle::getRadius()
{
	 return this->radius;
}

 //2- Implement the promptForCircle method. It should ask for a Circle as follows:
 //Enter x: 1 .  Enter y : 2 .  Enter radius : 3
 void Circle::promptForCircle()
 { 
	 //Please note that the Point class has a method called promptForPoint. Make sure
	 //you call this from your method to re-use code!
	 promptForPoint(); 

	 cout << "Enter radius: ";
	 cin >> this->radius;
 }

 void Circle::display() 
 { 
	 //3- Implement the display method. It should display a Circle as follows:
	 //(1, 2) - Radius: 3
	 //Please note that the Point class has a method called display. Make sure you call
	 //this from your method to re-use code! (Yes, these methods should both be called "display")
	  Point::display();
	  cout << " - Radius: " << getRadius() << endl;

 }