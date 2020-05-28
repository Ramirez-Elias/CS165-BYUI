/***********************************************************************
 * Implementation File:
 *    SHIP: A class representing the SHIP
 * Author:
 *    Elias Ramirez
 * Summary:
 *    Everything you needed to know about the lander but were afraid to ask
 ************************************************************************/

#include "ship.h"


Point Ship::getPoint() const
{
	return this->position;
}
Velocity Ship::getVelocity() const
{
	return this->velocity;
}
bool Ship::isAlive()
{
	return this->m_isAlive;
}
void Ship::setAlive(bool isAlive)
{
	this->m_isAlive = isAlive;
}

void Ship::applyThrustLeft()
{
	//The lander should not continue to move after crashing or landing.
	
		//The left and right thrust amounts are 0.1 pixels per frame, and consume

		velocity.setDx(velocity.getDx() + 0.1);


}
void Ship::applyThrustRight()
{
	//The lander should not continue to move after crashing or landing.

		//The left and right thrust amounts are 0.1 pixels per frame, and consume 
		// 1 unit of fuel.
		velocity.setDx(velocity.getDx() - 0.1);

}
void Ship::applyThrustBottom()
{
	
		//The upward thrust (caused by the down arrow) amount is 0.3 pixels per frame, and
		//consumes 3 units of fuel.
		velocity.setDy(velocity.getDy() + 0.3);

}
void Ship::advance()
{
	
	//check if alive
	if (isAlive())
	{

		//The ship obeys the laws of motion.When in motion, the ship will
		//tend to stay in motion.
		position.addX(velocity.getDx());
		position.addY(velocity.getDy());
		
	}
}

void Ship::draw()
{
	//Requierements
	//3- You need to fill in the draw method for the Lander class to draw it on the 
	// screen(You don't have to draw it at the "correct" location at this point, 
	//just somewhere on the screen).
	drawShip(position, ROTATE_AMOUNT, THRUST_AMOUNT);
}