/*************************************************************
* File: velocity.cpp
* Author:  Elias Ramirez
*
* Description: Contains the implementations of the
*  method bodies for the velocity class.
*************************************************************/
#include "velocity.h"

Velocity::Velocity(float xVelocity, float yVelocity)
{
	this->xVelocity = xVelocity;
	this->yVelocity = yVelocity;
}

float Velocity::getDx()
{
	return this->xVelocity;
}
float Velocity::getDy()
{
	return this->yVelocity;
}
void Velocity::setDx(float xVelocity)
{
	this->xVelocity = xVelocity;
}
void Velocity::setDy(float yVelocity)
{
	this->yVelocity = yVelocity;
}