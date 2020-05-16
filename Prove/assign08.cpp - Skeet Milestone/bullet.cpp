#include "Bullet.h"

Bullet::Bullet()
{
	//it is much easier to start bullets at the corner of the screen (inside the rifle) than at the tip of the 
	// barrel, and this will be sufficient as long as the angle is correct.
	//set initial position-200y 200x
	position.setX(200);
	position.setY(-200);
}

void Bullet::fire(Point point, float angle)
{
	//newBullet.fire(rifle.getPoint(), rifle.getAngle());
	velocity.setDx(BULLET_SPEED * (-cos(M_PI / 180.0 * angle)));
	velocity.setDy(BULLET_SPEED * (sin(M_PI / 180.0 * angle)));
}

void Bullet::draw()
{
	//Rendered as a dot.
	//A drawDot function is included in the uiDraw library to assist you.
	drawDot(position);
}