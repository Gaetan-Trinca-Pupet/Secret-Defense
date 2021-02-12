#include "../../../header/miniJeu/Bronx/Deliverable.h"


Deliverable::Deliverable(sf::Texture* texture, bool _stored)
{
	isGrabbable = true;
	setStored(_stored);
	setTexture(texture);
	setSize(sf::Vector2f(texture->getSize()));
	setOrigin(sf::Vector2f(0, texture->getSize().y));
    targetZone = nullptr;
}

void Deliverable::setTarget(sf::RectangleShape* zone)
{
    targetZone = zone;
}

void Deliverable::setCanBeGrabbed(bool val)
{
	isGrabbable = val;
}

bool Deliverable::canBeGrabbed()
{
	return isGrabbable;
}

void Deliverable::onRelease()
{
    if (targetZone != nullptr && getGlobalBounds().intersects(targetZone->getGlobalBounds()))
		setStored(true);
}

void Deliverable::onGrab()
{
	setStored(false);
}

void Deliverable::update()
{
}

void Deliverable::setStored(bool val)
{
	if (val)
	{
		stored = true;
		setFillColor(sf::Color(190, 190, 190));
	}
	else
	{
		stored = false;
		setFillColor(sf::Color(255, 255, 255));
	}
}

bool Deliverable::isStored()
{
    return stored;
}

bool Deliverable::isInTargetZone()
{
    return getGlobalBounds().intersects(targetZone->getGlobalBounds());
}
