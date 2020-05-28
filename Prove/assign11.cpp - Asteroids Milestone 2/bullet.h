#include "flyingObject.h"
#include <cmath>
#ifndef BULLET_H
#define BULLET_H

#define BULLET_SPEED 5
#define BULLET_LIFE 40 // added new
#define M_PI           3.14159265358979323846  /* pi */


/*********************************************
 * Bullet
 *********************************************/
class Bullet : public FlyingObject
{
public:
	Bullet();
	~Bullet() {}
	void fire(Point point, float angle);
	virtual void draw();
private:

};


#endif
