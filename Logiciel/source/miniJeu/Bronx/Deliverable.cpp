#include "../../../header/miniJeu/Bronx/Deliverable.h"


Deliverable::Deliverable(sf::Texture* texture, bool _stored)
{
	setStored(_stored);
	setTexture(texture);
	setSize(sf::Vector2f(texture->getSize()));
	deliverZone = nullptr;
}

void Deliverable::setTarget(sf::RectangleShape* zone)
{
	deliverZone = zone;
}

void Deliverable::onRelease()
{
	if (getGlobalBounds().intersects(deliverZone->getGlobalBounds()))
	{
		setStored(true);
	}
}

void Deliverable::onGrab()
{
	setStored(false);
}

void Deliverable::update()
{
	if (!stored && getPosition().y + getSize().y > groundLevel)
	{
		//TODO: gravité
	}
}

void Deliverable::setStored(bool val)
{
	if (val)
	{
		stored = true;
		setFillColor(sf::Color(190, 190, 190));
		setScale(0.8, 0.8);
	}
	else
	{
		stored = false;
		setFillColor(sf::Color(255, 255, 255));
		setScale(1, 1);
	}
}

bool Deliverable::isStored()
{
	return stored;
}

void Deliverable::putDown()
{
	groundLevel = getPosition().y + getTexture()->getSize().y;
}
