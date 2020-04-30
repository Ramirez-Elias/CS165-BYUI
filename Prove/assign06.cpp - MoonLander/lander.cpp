
#include "lander.h"
#include "uiDraw.h"


/**********************************************************************
* Function: draw()
* Purpose: Draws the lander.
**********************************************************************/
void Lander::draw()
{
	drawLander(lP);
}

/**********************************************************************
* Function: applyGravity()
* Purpose: Applys gravity to the lander.
**********************************************************************/
float Lander::applyGravity(float gravity)
{ 
	landV.setV(0.0, -gravity);
	return gravity;
}

/**********************************************************************
* Function: applyThrustLeft()
* Purpose: Moves lander to the right.
**********************************************************************/
void Lander::applyThrustLeft()
{
	if (fuel > 0)
	{
		landV.setV(THRUST_HORIZONTAL, 0.0);

		fuel = (fuel - 1);

		if (fuel <= 0)
		{
			setFuel(0);
		}
	}
}

/**********************************************************************
* Function: applyThrustRight()
* Purpose: Moves lander to the left.
**********************************************************************/
void Lander::applyThrustRight()
{
	if (fuel > 0)
	{
		landV.setV(-THRUST_HORIZONTAL, 0.0);

		fuel = (fuel - 1);

		if (fuel <= 0)
		{
			setFuel(0);
		}
	}
}

/**********************************************************************
* Function: applyThrustBottom()
* Purpose: Moves the lander in an upward direction.
**********************************************************************/
void Lander::applyThrustBottom()
{
	if (fuel > 0)
	{
		landV.setV(0.0, THRUST_VERTICAL);

		fuel = (fuel - 3);

		if (fuel <= 0)
		{
			setFuel(0);
		}
	}
}

/**********************************************************************
* Function: advance()
* Purpose: Advances the lander.
**********************************************************************/
void Lander::advance()
{
	lP.addX(landV.getDx());
	lP.addY(landV.getDy());
}

/**********************************************************************
* Function: reset()
* Purpose: This resets the lander to a new random position.
**********************************************************************/
void Lander::reset()
{
	fuel = 500;
	setAlive(true);
	setLanded(false);
	landV.setV(random(0, 3), random(0, 3));
}





