/***********************************************************************
 * Header File:
 *    Ship : The representation of a position on the screen
 * Author:
 *     Elias Ramirez
 * Summary:
 *
 * 1- The ship obeys the laws of motion. When in motion, the ship will
 *    tend to stay in motion.
 * 2- Note that the angle or orientation of the ship can be different
 *    than the direction it is traveling.
 * 3- The right and left arrows rotate the ship 6 degrees to either 
 *    direction.
 * 4- The up arrow will increase the velocity in the direction the ship 
 *    is pointed by 0.5 pixels/frame.
 * 5- For collision detection, you can assume the ship is a circle of
 *    radius 10.
 * 6- A drawShip function is included in the uiDraw library to assist you.
 ************************************************************************/
#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#include "velocity.h"
#include "point.h"
#include "uiDraw.h"
#include <iostream>

 /*********************************************
  * SHIP
  * A single position.
  *********************************************/
class Ship
{
private:
	Point position;
	Velocity velocity;
	bool m_isAlive;

public:
	Ship() : position(), velocity(), m_isAlive(true) {};
	Point getPoint() const;
	Velocity getVelocity() const;
	bool isAlive();
	void setAlive(bool isAlive);
	void applyThrustLeft();
	void applyThrustRight();
	void applyThrustBottom();
	void advance();
	void draw();
};

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Ship & pt);
std::istream & operator >> (std::istream & in, Ship & pt);




#endif /* ship_h */
