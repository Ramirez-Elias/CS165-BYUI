#include "flyingObjects.h"
#ifndef BULLET_H
#define BULLET_H
#define BULLET_SPEED 10.0

/*********************************************
 * Bullet
 *********************************************/
class Bullet : public FlyingObject
{
public:
	Bullet();
	~Bullet() {}
	void fire(Point point, float position);
	virtual void draw();
private:

};


#endif
