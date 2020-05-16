#include "Bird.h"

/*********************************************
* Bird Base Class
*********************************************/
//The hit() method for the Bird represents the bird being hit and should
//either kill the bird (or decrement the number of hits remaining for the
//tough bird) and return an integer representing the points scored for that hit.
int Bird::hit()
{
	//Decrease the number of lives
	this->lives--;
	//check if hit killed the bird
	if (this->lives == 0)
	{
		kill();
		//bonus?
		if (this->bonus)
			return this->score + this->bonus;
	}

	return getScore();
}

 Bird::Bird()
{
	 //The initial position of the bird is anywhere along the left side the screen
	 position.setX(-200);
	 position.setY(random(-150, 150));
	 //The horizontal component of the velocity should be between 3 and 6 pixels/frame.
	 velocity.setDx(random(3, 6));
	//If the bird starts on the top half of the screen, it should have a generally 
	//downward velocity(down and to the right at amounts defined below).
	 if (position.getY() >= 0)
	 {
		 //The vertical component of the velocity should be between -4 and +4 pixels/frame
		 //(positive or negative depending on whether it starts on the top or bottom half of the screen).
		 velocity.setDy(random(-4, -1));
	 }
	 else
		 velocity.setDy(random(1, 4));
}

/*********************************************
* BirdStandard Class
*********************************************/
 void BirdStandard::draw()
 {
	 drawCircle(getPoint(), 15);
 }

 /*********************************************
 * BirdTough Class
 *********************************************/
 BirdTough::BirdTough()
 {
	 //A bonus of 2 points is awarded if it is destroyed. 
	 setLives(3);
	 setBonus(2);
 }

 void BirdTough::draw()
 {
	 //Rendered as a circle with a number inside of it.
	 //A drawToughBird function is included in the uiDraw library to assist you.
	 //It takes 3 hits to destroy this bird.
	 drawToughBird(getPoint(),15,getLives());
 }

/*********************************************
* BirdTough Class
*********************************************/
 BirdSacred::BirdSacred()
 {
	 //A penalty of 10 points is lost if this bird is hit.
	 setScore(-10);
 }

 void BirdSacred::draw()
 {
	 //Rendered as a star.
	 //A drawSacredBird function is included in the uiDraw library to assist you.
	 drawSacredBird(getPoint(), 15);
 }
