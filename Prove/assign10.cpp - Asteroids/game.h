/*************************************************************
 * File: game.h
 * Author: Elias Ramirez
 *
 *************************************************************/
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "flyingObject.h"
#include "bullet.h"
#include "ship.h"
#include "rocks.h"

#define CLOSE_ENOUGH 15
#define OFF_SCREEN_BORDER_AMOUNT 5

/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
	/*********************************************
	 * Constructor
	 * Initializes the game
	 *********************************************/
	Game(Point tl, Point br);
	~Game();

	/*********************************************
	 * Function: handleInput
	 * Description: Takes actions according to whatever
	 *  keys the user has pressed.
	 *********************************************/
	void handleInput(const Interface & ui);

	/*********************************************
	 * Function: advance
	 * Description: Move everything forward one
	 *  step in time.
	 *********************************************/
	void advance();

	/*********************************************
	 * Function: draw
	 * Description: draws everything for the game.
	 *********************************************/
	void draw(const Interface & ui);

	/*********************************************
    * Function: getClosestDistance
    * Description: draws everything for the game.
    *********************************************/
	float getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const;

private:
	// The coordinates of the screen
	Point topLeft;
	Point bottomRight;

	int score;

	//Rifle rifle; <- Maybe the Ship? 
	std::vector<Bullet> bullets;

	//Rock Vector and object created
	std::vector<Rock*> rocks;
	Rock * rock;

	/*************************************************
	 * Private methods to help with the game logic.
	 *************************************************/
	bool isOnScreen(const Point & point);
	void advanceBullets();
	void advanceRock();
	Rock* createRock();

	void handleCollisions();
	void cleanUpZombies();
};

#endif /* GAME_H */
