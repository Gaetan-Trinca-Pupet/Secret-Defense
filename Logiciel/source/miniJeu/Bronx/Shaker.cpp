#include "..\..\..\header\miniJeu\Bronx\Shaker.h"

Shaker::Shaker(sf::RenderWindow* w): canBeShaked(false), canFill(false), shakeAmount(0), isFilling(false), window(w)
{
	setTexture(&AssetManager::getTexture("../ressource/Bronx/shaker.png"));
	setSize(sf::Vector2f(getTexture()->getSize()));
	setOrigin(sf::Vector2f(0, getTexture()->getSize().y));

    pisse1.setTexture(AssetManager::getTexture("../ressource/Bronx/liquid_start.png"));
    pisse2.setTexture(AssetManager::getTexture("../ressource/Bronx/liquid.png"));
    AssetManager::getTexture("../ressource/Bronx/liquid.png").setRepeated(true);

	shakeTreshold = 25000; //TODO: ajuster avec difficulté
}

Shaker::~Shaker()
{
}

void Shaker::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sf::RectangleShape(*this));
    if(isFilling)
    {
        window->draw(pisse1);
        window->draw(pisse2);
    }
}

void Shaker::onGrab()
{
	lastpos = getPosition();
    if(canFill)
    {
        setRotation(105);
        setPosition(getPosition().x,getPosition().y-getSize().y);
    }
}

void Shaker::updateOnGrab()
{
	if (!canBeShaked) return;

	int dist = sqrt(pow(getPosition().x - lastpos.x, 2) + pow(getPosition().y - lastpos.y, 2));

	if (dist > 30)
	{
		shakeAmount += dist;
	}

    lastpos = getPosition();
}

//changer le onRelease et mettre quelque chose qui vérifie si on est au dessus d'un verre, sans avoir à le lâcher
void Shaker::onRelease()
{
    if(!canFill) return;
    setRotation(0);
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

void Shaker::fillUp(std::vector<Verre> &verres)
{
    sf::Vector2f point (getGlobalBounds().left+getGlobalBounds().width, getGlobalBounds().top+getGlobalBounds().height);
    for (Verre &v : verres)
    {
        isFilling=false;
        if(v.isUnderShaker(point))
        {
            isFilling=true;
            pisse1.setPosition(point.x+15,point.y);

            pisse2.setPosition(point.x+15,point.y+20);
            v.setFull(true);
        }
    }
}
