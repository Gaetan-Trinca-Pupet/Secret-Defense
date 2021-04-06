#ifndef __GRAVITYAFFECTED_H_
#define __GRAVITYAFFECTED_H_

#include <SFML/Graphics.hpp>
#include "Grabber.hpp"

class GravityAffected: public Grabber::Grabbable
{
public:

	GravityAffected();
	virtual void onRelease();
	void applyVelocity();
	void putDown();
	static void setGetGroundLevelFunc(float (*_getGroundLevel)(sf::Vector2f));
    void updateGroundLevel();

private:

	void applyGravity();
	static float (*getGroundLevel)(sf::Vector2f);
	float groundLevel;
	float speed;
	float velocity;

};

#endif
