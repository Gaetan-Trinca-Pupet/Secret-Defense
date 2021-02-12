#ifndef __GRAVITYAFFECTED_H_
#define __GRAVITYAFFECTED_H_

#include <SFML/Graphics.hpp>

class GravityAffected: public sf::Transformable
{
public:

	GravityAffected();
	void applyVelocity();
	void putDown();

private:

	void applyGravity();
	float groundLevel;
	float speed;
	float velocity;

};

#endif
