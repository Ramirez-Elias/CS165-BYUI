/***********************************************************************
 * Header File:
 *    Lander : The representation of a position on the screen
 * Author:
 *     Elias Ramirez
 * Summary:
 *    Everything we need to know about a location on the screen, including
 *    the location and the bounds.
 ************************************************************************/


#ifndef LANDER_H
#define LANDER_H
#include "velocity.h"
#include "point.h"
#include "uiDraw.h"
#include <iostream>

 /*********************************************
  * LANDER
  * A single position.
  *********************************************/
class Lander
{
private:
	Point position;
	Velocity velocity;
	bool m_isAlive;
	bool m_isLanded;
	int m_fuel;
	bool m_canTrust;
	float m_gravity;
public:
	Lander(): position(), velocity(), m_isAlive(true), m_isLanded(false), m_canTrust(true) {};
	Point getPoint() const;
	Velocity getVelocity() const;
	bool isAlive();
	bool isLanded();
	int getFuel();
	bool canThrust();
	void setLanded(bool isLanded);
	void setAlive(bool isAlive);
	void setFuel(int fuel);
	void applyGravity(float gravity);
	void applyThrustLeft();
	void applyThrustRight();
	void applyThrustBottom();
	void advance();
	void draw();
};

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Lander & pt);
std::istream & operator >> (std::istream & in, Lander & pt);

#endif // LANDER_H