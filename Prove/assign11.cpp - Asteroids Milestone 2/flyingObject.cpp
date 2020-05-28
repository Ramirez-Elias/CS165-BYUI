#include "flyingObject.h"


//Setters and getters for position
Point FlyingObject::getPoint() const
{
	return this->position;
}

void FlyingObject::setPoint(Point position)
{
	this->position = position;
}

//Setters and getters for velocity
Velocity FlyingObject::getVelocity() const
{
	return this->velocity;
}

void FlyingObject::setVelocity(Velocity velocity)
{
	this->velocity = velocity;
}

//Setters and getters for lives
void FlyingObject::setLives(int lives)
{
	this->lives = lives;
}
int FlyingObject::getLives()
{
	return this->lives;
}

//Setters and getters for score
void FlyingObject::setScore(int score)
{
	this->score = score;
}
int FlyingObject::getScore()
{
	return this->score;
}

//Setters and getters for bonus
void FlyingObject::setBonus(int bonus)
{
	this->bonus = bonus;
}
int FlyingObject::getBonus()
{
	return this->bonus;
}

//Setters and getters for isAlive
void FlyingObject::setIsAlive(bool alive)
{
	this->alive = alive;
}

bool FlyingObject::isAlive() const
{
	return this->alive;
}

void FlyingObject::kill()
{
	setIsAlive(false);
}

void FlyingObject::advance()
{
	position.addX(velocity.getDx());
	position.addY(velocity.getDy());
}


