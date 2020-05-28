/***********************************************************************
* File:
*    Rocks.cpp
* Author:
*    Elias Ramirez
*  
* Summary
*  The rocks.h and rocks.cpp files are intended to hold all three of your 
*  asteroid classes (BigRock, MediumRock, SmallRock) plus a common base
*  class (Rock).
************************************************************************/
#include "rocks.h"


/*********************************************
* Rock Base Class
*********************************************/
//The hit() method for the Rock represents the rock being hit and should
//either kill the rock (or decrease the number of hits remaining for the
//tough Rock) and return an integer representing the points scored for that hit.
int Rock::hit()
{
	//Decrease the number of lives
	this->lives--;
	//check if hit killed the Rock
	if (this->lives == 0)
	{
		kill();
		//bonus?
		if (this->bonus)
			return this->score + this->bonus;
	}

	return getScore();
}

Rock::Rock()
{
	//The initial position of the Rock is anywhere along the left side the screen
	position.setX(-200);
	position.setY(random(-150, 150));


	//Moves at 1 pixel per frame, with a random initial angle.
	velocity.setDx(1);
	velocity.setDy(1);

}

/*********************************************
* BigRock Class
* Large Asteroids
*   Moves at 1 pixel per frame, with a random initial angle.
*   Rotates at 2 degrees per frame.
*   For collision detection, can be treated as a circle with radius 16.
*   If a large asteroid gets hit, it breaks apart and becomes two medium asteroids and one small one.
*   The first medium asteroid has the same velocity as the original large one plus 1 pixel/frame in the up direction.
*   The second medium asteroid has the same velocity as the original large one plus 1 pixel/frame in the down direction.
*   The small asteroid has the original velocity plus 2 pixels/frame to the right.
*   A drawLargeAsteroid function is included in the uiDraw library to assist you.
*********************************************/
BigRock::BigRock()
{


}

void BigRock::draw()
{
	//Rendered as a circle with a number inside of it.
	//A drawToughRock function is included in the uiDraw library to assist you.
	//It takes 3 hits to destroy this Rock.
	drawLargeAsteroid(position, BIG_ROCK_SPIN);
}



/*********************************************
*  MediumRock Class
*********************************************/
MediumRock::MediumRock(int number)
{
	setLives(1);
	//set speed
	
	// The first medium asteroid has the same velocity as the original large one
	// plus 1 pixel/frame in the up direction.
	if (number = 1)
		velocity.setDx(velocity.getDx()+1);
	else
		// The second medium asteroid has the same velocity as the original large 
		// one plus 1 pixel/frame in the down direction.
		velocity.setDx(velocity.getDx()-2);
}

void MediumRock::draw()
{
	drawMediumAsteroid(position, MEDIUM_ROCK_SPIN);
}


/*********************************************
* SmallRock Class
*********************************************/
SmallRock::SmallRock()
{
	setLives(1);
	//The small asteroid has the original velocity plus 2 pixels / frame to the right.
	velocity.setDy(velocity.getDy() + 2);
}

SmallRock::SmallRock(int number)
{
	setLives(1);

	// The small asteroid has the same velocity as the original medium one plus 3 
	// pixel/frame to the right.
	if (number = 1)
		velocity.setDx(velocity.getDx() + 3);
	else
		// The second, 3 pixels/frame to the left..
		velocity.setDx(velocity.getDx() - 4);
}

void SmallRock::draw()
{
	//Rendered as a star.
	//A drawSacredRock function is included in the uiDraw library to assist you.
	drawSmallAsteroid(position, SMALL_ROCK_SPIN);
	
}

