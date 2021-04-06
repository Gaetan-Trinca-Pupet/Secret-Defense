#include "../header/GravityAffected.h"

float (*GravityAffected::getGroundLevel)(sf::Vector2f) = nullptr;

GravityAffected::GravityAffected()
	: velocity(0), speed(0.1), groundLevel(490)
{
}

void GravityAffected::onRelease()
{
	updateGroundLevel();
	velocity = 0;
}

void GravityAffected::applyVelocity()
{
	
	if (getPosition().y >= groundLevel || isGrabbed) return;

	applyGravity();
	move(0, velocity * speed);

	if (getPosition().y > groundLevel)
        setPosition(getPosition().x, groundLevel);
}

void GravityAffected::setGetGroundLevelFunc(float (*_getGroundLevel)(sf::Vector2f))
{
	getGroundLevel = _getGroundLevel;
}

void GravityAffected::applyGravity()
{
	velocity += 9.81;
}

void GravityAffected::updateGroundLevel()
{
    groundLevel = (*getGroundLevel)(getPosition());
}
