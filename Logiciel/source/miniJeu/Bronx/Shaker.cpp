#include "..\..\..\header\miniJeu\Bronx\Shaker.h"

Shaker::Shaker(): canBeShaked(false), shakeAmount(0)
{
	setTexture(&AssetManager::getTexture("../ressource/Bronx/shaker.png"));
	setSize(sf::Vector2f(getTexture()->getSize()));
	setOrigin(sf::Vector2f(0, getTexture()->getSize().y));

	shakeTreshold = 999; //TODO: ajuster avec difficulté
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
		std::cout << dist << std::endl;
	}
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
