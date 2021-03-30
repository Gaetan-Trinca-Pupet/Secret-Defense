#include "..\..\..\header\miniJeu\Bronx\Shaker.h"

Shaker::Shaker(sf::RenderWindow* w, int difficulty): canBeShaked(false), canFill(false), shakeAmount(0), incrementChute(0), incrementAnim(20), isFilling(false), window(w)
{
	setTexture(&AssetManager::getTexture("../ressource/Bronx/shaker.png"));
	setSize(sf::Vector2f(getTexture()->getSize()));
	setOrigin(sf::Vector2f(0, getTexture()->getSize().y));

    liquide1.setTexture(AssetManager::getTexture("../ressource/Bronx/liquid_start.png"));
    liquide2.setTexture(AssetManager::getTexture("../ressource/Bronx/liquid.png"));
    liquide2.setTextureRect(sf::IntRect(0,0,15,60));
    AssetManager::getTexture("../ressource/Bronx/liquid.png").setRepeated(true);

	shakeTreshold = (difficulty / (1 + difficulty)) * 14000 + 16000;
}

Shaker::~Shaker()
{
}

void Shaker::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sf::RectangleShape(*this));
    if(isFilling)
    {
        window->draw(liquide1);
        window->draw(liquide2);
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
    GravityAffected::onRelease();
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
    isFilling=false;
    if(!isGrabbed)
        return;
    sf::Vector2f point (getGlobalBounds().left+getGlobalBounds().width, getGlobalBounds().top+getGlobalBounds().height);
    for (Verre &v : verres)
    {
        if(v.isUnderShaker(point))
        {
            incrementChute+=20;
            incrementAnim-=1;
            if(incrementChute>v.getGlobalBounds().top-point.y+10)
                incrementChute=v.getGlobalBounds().top-point.y+10;
            if(incrementAnim<0)
                incrementAnim=20;
            isFilling=true;
            liquide1.setPosition(point.x-10,point.y-25);

            liquide2.setPosition(point.x-10,point.y-5);
            liquide2.setTextureRect(sf::IntRect(0,incrementAnim,15,incrementChute+10));
            v.setFull(true);
        }
    }
    if(!isFilling)
        incrementChute=0;
}
