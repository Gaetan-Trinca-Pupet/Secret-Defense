#include "../header/GravityAffected.h"

GravityAffected::GravityAffected(): velocity(0), groundLevel(540), speed(1)
{
	
}

void GravityAffected::applyVelocity()
{
	if(getPosition().y <= groundLevel) return

	move(0, velocity * speed);

	if (getPosition().y < groundLevel) setPosition(getPosition().x, getPosition().y);
}

void GravityAffected::applyGravity()
{
	velocity += 9.81;
}
