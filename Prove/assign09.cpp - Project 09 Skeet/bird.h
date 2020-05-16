/***********************************************************************
* Header File:
*    bird
* Author:
*    Elias Ramirez
* Summary:
************************************************************************/
#include "flyingObjects.h"
#ifndef BIRD_H
#define BIRD_H

/*********************************************
 * Bird Base Class
 *********************************************/
class Bird : public FlyingObject
{
public:
	Bird();
	~Bird() {}
	int hit();
private:

};

/*********************************************
 * BirdStandard Class
 *********************************************/
class BirdStandard: public Bird
{
public:
	BirdStandard() {}
	~BirdStandard() {}
	virtual void draw();
	virtual void advance(Bird & BirdStandard) {};
private:

};

/*********************************************
 * BirdTough Class
 *********************************************/
class BirdTough : public Bird
{
public:
	BirdTough();
	~BirdTough() {}
	virtual void draw();
	virtual void advance(Bird & BirdTough) {};
private:

};

/*********************************************
 * BirdSacred Class
 *********************************************/
class BirdSacred : public Bird
{
public:
	BirdSacred();
	~BirdSacred() {}
	virtual void draw();
	virtual void advance(Bird & BirdSacred) {};
private:

};


#endif
