#include "..\..\..\header\miniJeu\Bronx\Shaker.h"

Shaker::Shaker(sf::RenderWindow* w): canBeShaked(false), shakeAmount(0), window(w)
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
	std::cout << (isShakingFinished() ? "finis" : std::to_string(shakeAmount)) << std::endl;

	lastpos = getPosition();
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
