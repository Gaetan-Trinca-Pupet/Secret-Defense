#ifndef __DELIVERABLE_H_
#define __DELIVERABLE_H_

#include "../../Grabber.hpp"

class Deliverable : public Grabber::Grabbable
{
public:


	sf::RectangleShape* deliverZone;

    Deliverable(sf::Texture* texture, bool _stored = false);

	void setTarget(sf::RectangleShape* zone);

	void setCanBeGrabbed(bool val);

	virtual bool canBeGrabbed();

	virtual void onRelease();

	virtual void onGrab();

	void update();

	void setStored(bool val);

	bool isStored();

	void putDown();

private:

	int groundLevel;
	bool isGrabbable;

protected:

	bool stored;

};

#endif
