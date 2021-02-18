#ifndef __DELIVERABLE_H_
#define __DELIVERABLE_H_

#include "../../GravityAffected.h"

class Deliverable : public GravityAffected
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

	bool isDelivered();

private:
	bool isGrabbable;

protected:
    sf::RectangleShape* targetZone;

	bool stored;
	bool delivered;
};

#endif
