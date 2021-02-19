#include "..\..\..\header\miniJeu\Bronx\Shaker.h"

Shaker::Shaker(sf::RenderWindow* w): canBeShaked(false), canFill(false), shakeAmount(0), window(w)
{
	setTexture(&AssetManager::getTexture("../ressource/Bronx/shaker.png"));
	setSize(sf::Vector2f(getTexture()->getSize()));
	setOrigin(sf::Vector2f(0, getTexture()->getSize().y));

	shakeTreshold = 25000; //TODO: ajuster avec difficulté
}

Shaker::~Shaker()
{
}

void Shaker::onGrab()
{
	lastpos = getPosition();
}

void Shaker::updateOnGrab()
{
	if (!canBeShaked) return;

	int dist = sqrt(pow(getPosition().x - lastpos.x, 2) + pow(getPosition().y - lastpos.y, 2));

	if (dist > 20)
	{
		shakeAmount += dist;
	}

    lastpos = getPosition();
}

//changer le onRelease et mettre quelque chose qui vérifie si on est au dessus d'un verre, sans avoir à le lâcher
void Shaker::onRelease()
{
    if(!canFill) return;
}

bool Shaker::isShakingFinished()
{
	return shakeAmount > shakeTreshold;
}

void Shaker::startShaking()
{
	canBeShaked = true;

    shakeAmount = 0;
}

void Shaker::startFilling()
{
    canFill=true;
}
