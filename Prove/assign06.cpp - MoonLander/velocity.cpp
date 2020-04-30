
#include "velocity.h"

/**********************************************************************
* Function: reset()
* Purpose: Resets the velocity variables for a new instance of velocity
**********************************************************************/
void Velocity::setV(float newDx, float newDy)
{
	dx = dx + newDx;
	dy = dy + newDy;
}