#ifndef __DELIVERABLE_H_
#define __DELIVERABLE_H_

#include "../../Grabber.hpp"
#include "../../GravityAffected.h"

class Deliverable : public Grabber::Grabbable, public GravityAffected
{
public:
    Deliverable(sf::Texture* texture, bool _stored);

	void setTarget(sf::RectangleShape* zone);

	void setCanBeGrabbed(bool val);

	virtual bool canBeGrabbed();

	virtual void onRelease();

	virtual void onGrab();

	void update();

	void setStored(bool val);

	bool isStored();

    bool isInTargetZone();

private:
	bool isGrabbable;

protected:
    sf::RectangleShape* targetZone;

	bool stored;
};

#endif
