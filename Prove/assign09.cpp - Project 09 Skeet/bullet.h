#include "flyingObjects.h"
#include <cmath>
#ifndef BULLET_H
#define BULLET_H
//Bullets travel at 10 pixels/frame at that angle at which they are fired.
#define BULLET_SPEED 10.0

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
