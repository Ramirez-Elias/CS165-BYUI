/***********************************************************************
 * Implementation File:
 *    LANDER : A class representing the lunar landscape
 * Author:
 *    Elias Ramirez
 * Summary:
 *    Everything you needed to know about the lander but were afraid to ask
 ************************************************************************/

#include "lander.h"


Point Lander::getPoint() const
{
	return this->position;
}
Velocity Lander::getVelocity() const
{
	return this->velocity;
}
bool Lander::isAlive()
{
	return this->m_isAlive;
}
bool Lander::isLanded()
{
	return this->m_isLanded;
}
int Lander::getFuel()
{
	return this->m_fuel;
}
bool Lander::canThrust()
{
	return this->m_canTrust;
}
void Lander::setLanded(bool isLanded)
{
	this->m_isLanded = isLanded;
}
void Lander::setAlive(bool isAlive)
{
	this->m_isAlive = isAlive;
}
void Lander::setFuel(int fuel)
{
	this->m_fuel = fuel;
}
void Lander::applyGravity(float gravity)
{
	//Gravity on the moon can be modeled as 0.1 pixels per frame.
	velocity.setDy(velocity.getDy() - 0.1);
}
void Lander::applyThrustLeft()
{
	//	//The lander should not continue to move after crashing or landing.
	if (canThrust())
	{
		//The left and right thrust amounts are 0.1 pixels per frame, and consume
		// 1 unit of fuel.
		velocity.setDx(velocity.getDx() + 0.1);
		setFuel(getFuel() - 1);
	}
}
void Lander::applyThrustRight()
{
	//The lander should not continue to move after crashing or landing.
	if (canThrust())
	{
		//The left and right thrust amounts are 0.1 pixels per frame, and consume 
		// 1 unit of fuel.
		velocity.setDx(velocity.getDx() - 0.1);
		setFuel(getFuel() - 1);
	}
}
void Lander::applyThrustBottom()
{
	//The lander should not continue to move after crashing or landing.
	if (canThrust())
	{
		//The upward thrust (caused by the down arrow) amount is 0.3 pixels per frame, and
		//consumes 3 units of fuel.
		velocity.setDy(velocity.getDy() + 0.3);
		setFuel(getFuel() - 3);
	}
}
void Lander::advance()
{
	//check fuel
	if (getFuel()== 0)
	{
		//if empty, then it can't thrust
		this->m_canTrust = false;
	}

	//check if alive
	if (isAlive())
	{
		//check if landed?
		if (isLanded())
		{
			//do nothing (is alive and landed)
		}
		else
		{
			//The lander should have inertia, in other words, once it begins moving left, 
			//it should continue moving left unless additional thrust is made.
			position.addX(velocity.getDx());
			position.addY(velocity.getDy());
		}
		}
	}

void Lander::draw()
{
	//Requierements
	//3- You need to fill in the draw method for the Lander class to draw it on the 
	// screen(You don't have to draw it at the "correct" location at this point, 
	//just somewhere on the screen).
	drawLander(position);
}