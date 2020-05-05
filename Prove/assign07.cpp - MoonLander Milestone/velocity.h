/*********************************************
* Header file:
*    velocity.h
* Author:
*    Elias D Ramirez
* Summary:
*    This module will create a velocity class that 
*    will held the value to be passed to Point 
*    class in order to move the lander on the screen
*    and apply inertia to moves.
**********************************************/
#ifndef velocity_h
#define velocity_h
#include <iostream>
/*********************************************
* Velocity Class.
*********************************************/
class Velocity
{
public:
	Velocity() {};
	~Velocity() {};
	Velocity(float xVelocity, float yVelocity);
	float getDx();
	float getDy();
	void setDx(float xVelocity);
	void setDy(float yVelocity);
private:
	//(private data is up to you)
	float xVelocity;
	float yVelocity;
};

#endif