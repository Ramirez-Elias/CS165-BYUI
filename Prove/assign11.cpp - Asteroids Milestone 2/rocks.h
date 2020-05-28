/***********************************************************************
* Header File:
*    Rock
* Author:
*    Elias Ramirez
* Summary:
* The following classes are defined here: 
*   Rock
*   BigRock
*   MediumRock
*   SmallRock
************************************************************************/
#include "flyingObject.h"

#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10


/*********************************************
 * Rock Base Class
 *********************************************/
class Rock : public FlyingObject
{
public:
	Rock();
	~Rock() {}
	int hit();

private:

};

/*********************************************
 * MediumRock Class
 *********************************************/
class MediumRock : public Rock
{
public:
	MediumRock() {}
	MediumRock(int number);
	~MediumRock() {}
	virtual void draw();
	virtual void advance(Rock & MediumRock) {};
private:

};

/*********************************************
 * BigRock Class
 *********************************************/
class BigRock : public Rock
{
public:
	BigRock();
	~BigRock() {}
	virtual void draw();
	virtual void advance(Rock &  BigRock) {};
private:

};

/*********************************************
 * SmallRock Class
 *********************************************/
class SmallRock : public Rock
{
public:
	SmallRock();
	SmallRock(int number);
	~SmallRock() {}
	virtual void draw();
	virtual void advance(Rock & SmallRock) {};
private:

};


#endif /* rocks_h */
