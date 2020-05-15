#include "Bird.h"


//The hit() method for the Bird represents the bird being hit and should
//either kill the bird (or decrement the number of hits remaining for the
//tough bird) and return an integer representing the points scored for that hit.
int Bird::hit()
{
	return getLives()- 1;
}

 Bird::Bird()
{
	 //The initial position of the bird is anywhere along the left side the screen
	 position.setX(-150);
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

 void BirdStandard::draw()
 {
	 drawCircle(position, 15);
 }

 /*
	 //Standard Bird
	 if (birdType = 0)
	 {
		this->lives = 1;
		this->score = 1;
		this->bonus = 0;
	 }
	 //Tough Bird
	 else if (birdType = 1)
	 {
		 this->lives = 3;
		 this->score = 1;
		 this->bonus = 2;
	 }
	 //Sacred Bird
	 else
	 {
		 this->lives = 1;
		 this->score = -10;
		 this->bonus = 0;
	 }*/