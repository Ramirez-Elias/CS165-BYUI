
#ifndef LANDER_H
#define LANDER_H

#include "point.h"
#include "velocity.h"

#define THRUST_HORIZONTAL 0.1
#define THRUST_VERTICAL   0.3


/********************************************
* LANDER
* Vehical for landing on the cheese
********************************************/
class Lander
{
public:

	//Constructors
	Lander() : lP(150.0, 150.0), alive(true), landed(false) {}

	//Getters
	Point getPoint() const { return lP; }
	Velocity getVelocity() const { return landV; }


	int getFuel() { return fuel; }
	bool isAlive() { return alive; }
	bool isLanded() { return landed; }
	bool canThrust() { return thrust = true; }

	//Setters
	void setLanded(bool landed) { this->landed = landed; }
	void setAlive(bool alive) { this->alive = alive; }
	void setFuel(int fuel) { this->fuel = fuel; }

	//Functions
	float applyGravity(float gravity);
	void applyThrustLeft();
	void applyThrustRight();
	void applyThrustBottom();
	void advance();
	void reset();
	void draw();


private:
	Point lP;
	Velocity landV;
	bool alive;
	bool landed;
	int fuel;
	bool thrust;
	bool bottom;
	bool right;
	bool left;

};


#endif