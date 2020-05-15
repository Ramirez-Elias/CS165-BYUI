/***********************************************************************
* Header File:
*    FlyingObjects
* Author:
*    Elias Ramirez
* Summary:
************************************************************************/
#ifndef FLYINGOBJECTS_H
#define FLYINGOBJECTS_H
#include "velocity.h"
#include "point.h"
#include "uiDraw.h"
#include <iostream>

class FlyingObject
{
public:
	FlyingObject () : alive(true), lives(1), score(1), bonus(0) {}
	~FlyingObject() {}
	
	//Setters and getters 
	//position
	Point getPoint() const;
	void setPoint(Point position);
	
	//velocity
	void setVelocity(Velocity velocity);
	Velocity getVelocity() const;

	//lives
	void setLives(int lives);
	int getLives();

	//score
	void setScore(int score);
	int getScore();

	//bonus
	void setBonus(int bonus);
	int getBonus();

	//isAlive
	bool isAlive() const;
	void setIsAlive(bool alive);

	//+kill() : void
	void kill();

	//Virtual Classes. This will allow me to pverride this method in the Bird and bullet class
	// virtual advance() : void
	virtual void advance();

	//virtual draw() : void
	virtual void draw() = 0;

protected:
	Point position;
	Velocity velocity;
	bool alive;
	int lives;
	int score;
	int bonus;

};

#endif
