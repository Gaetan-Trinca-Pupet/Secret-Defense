#ifndef __DELIVERABLE_H_
#define __DELIVERABLE_H_

#include "../../Grabber.hpp"
#include "../../GravityAffected.h"

class Deliverable : public Grabber::Grabbable, public GravityAffected
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

	bool isGrabbable;

protected:

	bool stored;

};

#endif
