/*********************************************************************
* File: game.cpp
* Author: Elias Ramirez
* 
* Description: Contains the implementaiton of the game class
* methods.
*********************************************************************/
#include <limits>
#include <algorithm>
#include "game.h"
using namespace std;

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/

 float Game:: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
 {
	// find the maximum distance traveled
	float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
	dMax = max(dMax, abs(obj2.getVelocity().getDx()));
	dMax = max(dMax, abs(obj2.getVelocity().getDy()));
	dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.

	float distMin = std::numeric_limits<float>::max();
	for (float i = 0.0; i <= dMax; i++)
	{
	   Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
					  obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
	   Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
					  obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));

	   float xDiff = point1.getX() - point2.getX();
	   float yDiff = point1.getY() - point2.getY();

	   float distSquared = (xDiff * xDiff) +(yDiff * yDiff);

	   distMin = min(distMin, distSquared);
	}

	return sqrt(distMin);
 }
 

 /***************************************
  * GAME CONSTRUCTOR
  ***************************************/
 Game::Game(Point tl, Point br)
	 : topLeft(tl), bottomRight(br) //rifle(br)
 {
	 // Set up the initial conditions of the game
	 score = 0;

	 for (int i(0); i < 5; i++)
	 {
		 rocks.push_back(createRock());
	 }

	// rock = NULL;

 }

 /****************************************
  * GAME DESTRUCTOR
  ****************************************/
 Game :: ~Game()
 {
	 // TODO: Check to see if there is currently a rock allocated
	 //       and if so, delete it.
	 if (rock != NULL)
	 {
		 delete rock;
		 rock = NULL;
	 }
 }

 /***************************************
  * GAME :: ADVANCE
  * advance the game one unit of time
  ***************************************/
 void Game::advance()
 {
	 advanceBullets();
	 advanceRock();

	 handleCollisions();
	 cleanUpZombies();
 }

 /***************************************
  * GAME :: ADVANCE BULLETS
  * Go through each bullet and advance it.
  ***************************************/
 void Game::advanceBullets()
 {
	 // Move each of the bullets forward if it is alive
	 for (int i = 0; i < bullets.size(); i++)
	 {
		 if (bullets[i].isAlive())
		 {
			 // this bullet is alive, so tell it to move forward
			 bullets[i].advance();

			 if (!isOnScreen(bullets[i].getPoint()))
			 {
				 // the bullet has left the screen
				 bullets[i].kill();
			 }

		 }
	 }
 }

 /**************************************************************************
  * GAME :: ADVANCE Rock
  *
  * 1. If there is no Rock, create one with some probability
  * 2. If there is a Rock, and it's alive, advance it
  * 3. Check if the Rock has gone of the screen, and if so, "kill" it
  **************************************************************************/
 void Game::advanceRock()
 {

	 vector<Rock*>::iterator rockIt = rocks.begin();

	 while (rockIt != rocks.end())
	 {
		 Rock* pRock = *rockIt;
		
		 // Asteroids Hint:
		 // If we had a list of pointers, we would need this line instead:
		 //Bullet* pBullet = *bulletIt;

		 // we have a Rock, make sure it's alive
		 if (pRock->isAlive())
		 {
			 // move it forward
			 pRock->advance();

			 // check if the Rock has gone off the screen
			 if (!isOnScreen(pRock->getPoint()))
			 {
				 // We have missed the Rock
				 pRock->kill();
			 }
					
		 }

		 rockIt++; // advance

	 }


	/* if (rock == NULL)
	 {
		 // there is no Rock right now, possibly create one

		 // "resurrect" it will some random chance
		 if (random(0, 30) == 0)
		 {
			 // create a new Rock
			 rock = createRock();
		 }
	 }*/
	/* else
	 {
		 // we have a Rock, make sure it's alive
		 if (rock->isAlive())
		 {
			 // move it forward
			 rock->advance();

			 // check if the Rock has gone off the screen
			 if (!isOnScreen(rock->getPoint()))
			 {
				 // We have missed the Rock
				 rock->kill();
			 }
		 }
	 }*/

 }

/**************************************************************************
* GAME :: CREATE Rock
* Create a Rock of a random type according to the rules of the game.
**************************************************************************/
 Rock* Game::createRock()
 {
	 Rock* newRock = NULL;
	 newRock = new BigRock();	
	 return newRock;
 }

 /**************************************************************************
  * GAME :: IS ON SCREEN
  * Determines if a given point is on the screen.
  **************************************************************************/
 bool Game::isOnScreen(const Point & point)
 {
	 return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
		 && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
		 && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
		 && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
 }

 /**************************************************************************
  * GAME :: HANDLE COLLISIONS
  * Check for a collision between a Rock and a bullet.
  **************************************************************************/
 void Game::handleCollisions()
 {
	 // now check for a hit (if it is close enough to any live bullets)
	 for (int i = 0; i < bullets.size(); i++)
	 {
		 if (bullets[i].isAlive())
		 {
			 // this bullet is alive, see if its too close

			 // check if the Rock is at this point (in case it was hit)
			 if (rock != NULL && rock->isAlive())
			 {
				 // BTW, this logic could be more sophisiticated, but this will
				 // get the job done for now...
				 if (fabs(bullets[i].getPoint().getX() - rock->getPoint().getX()) < CLOSE_ENOUGH
					 && fabs(bullets[i].getPoint().getY() - rock->getPoint().getY()) < CLOSE_ENOUGH)
				 {
					 //we have a hit!

					 // hit the Rock
					 int points = rock->hit();
					 score += points;

					 // the bullet is dead as well
					 bullets[i].kill();
				 }
			 }
		 } // if bullet is alive

	 } // for bullets
 }

 /**************************************************************************
  * GAME :: CLEAN UP ZOMBIES
  * Remove any dead objects (take bullets out of the list, deallocate Rock)
  **************************************************************************/
 void Game::cleanUpZombies()
 {
	 // check for dead Rock
	 if (rock != NULL && !rock->isAlive())
	 {
		 // the Rock is dead, but the memory is not freed up yet
		 // TODO: Clean up the memory used by the Rock
		 delete rock;
		 rock = NULL;
	 }

	 // Look for dead bullets
	 vector<Bullet>::iterator bulletIt = bullets.begin();
	 while (bulletIt != bullets.end())
	 {
		 Bullet bullet = *bulletIt;
		 // Asteroids Hint:
		 // If we had a list of pointers, we would need this line instead:
		 //Bullet* pBullet = *bulletIt;

		 if (!bullet.isAlive())
		 {
			 // If we had a list of pointers, we would need to delete the memory here...


			 // remove from list and advance
			 bulletIt = bullets.erase(bulletIt);
		 }
		 else
		 {
			 bulletIt++; // advance
		 }
	 }

 }

 /***************************************
  * GAME :: HANDLE INPUT
  * accept input from the user
  ***************************************/
 void Game::handleInput(const Interface & ui)
 {
	 //MoveUp or Movedown should be included too.
	 // Change the direction of the rifle
	 if (ui.isLeft())
	 {
		// rifle.moveLeft();
	 }

	 if (ui.isRight())
	 {
		//rifle.moveRight();
	 }

	 // Check for "Spacebar
	 if (ui.isSpace())
	 {
		 Bullet newBullet;
		 newBullet.fire((200,-200), 45);

		 bullets.push_back(newBullet);
	 }
 }

 /*********************************************
  * GAME :: DRAW
  * Draw everything on the screen
  *********************************************/
 void Game::draw(const Interface & ui)
 {
	 vector<Rock*>::iterator rockIt = rocks.begin();

	 while (rockIt != rocks.end())
	 {
		 Rock* pRock = *rockIt;

		 if (pRock->isAlive())
		 {
			 // move it forward
			 pRock->draw();	
		 }

			 rockIt++; // advance
		
	 }
	 // draw the Rock

	 // TODO: Check if you have a valid Rock and if it's alive
	 // then call it's draw method
	/* if (rock != NULL && rock->isAlive())
	 {
		 rock->draw();
	 }*/

	 // draw the rifle
	 //rifle.draw();

	 // draw the bullets, if they are alive
	 for (int i = 0; i < bullets.size(); i++)
	 {
		 if (bullets[i].isAlive())
		 {
			 bullets[i].draw();
		 }
	 }

	 // Put the score on the screen
	 Point scoreLocation;
	 scoreLocation.setX(topLeft.getX() + 5);
	 scoreLocation.setY(topLeft.getY() - 5);

	 drawNumber(scoreLocation, score);

 }