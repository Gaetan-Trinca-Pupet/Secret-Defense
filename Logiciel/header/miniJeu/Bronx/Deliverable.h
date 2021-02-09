#ifndef __DELIVERABLE_H_
#define __DELIVERABLE_H_

#include "../../Grabber.hpp"

class Deliverable : public Grabber::Grabbable
{
public:


	sf::RectangleShape* deliverZone;

    Deliverable(const int& X, const int& Y, sf::Texture* texture, bool _stored = false);

	void setTarget(sf::RectangleShape* zone);

	virtual void onRelease();

	virtual void onGrab();

	virtual void update();

	void setStored(bool val);

	bool isStored();

	bool isComestible();

	void setTexture(const sf::Texture* texture, bool resetRect = false);

private:
	int groundLevel;
	bool stored;
	

};

#endif
