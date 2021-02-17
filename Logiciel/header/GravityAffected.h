#ifndef __GRAVITYAFFECTED_H_
#define __GRAVITYAFFECTED_H_

#include <SFML/Graphics.hpp>
#include "Grabber.hpp"

class GravityAffected: public Grabber::Grabbable
{
public:

	GravityAffected();
	void applyVelocity();
	void putDown();

private:

	void applyGravity();
	float (*getGroundLevel)(sf::Vector2f);
	float groundLevel;
	float speed;
	float velocity;

};

#endif
