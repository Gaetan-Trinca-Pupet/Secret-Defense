#include "..\..\..\header\miniJeu\Bronx\Verre.h"

Verre::Verre(sf::Texture *texture, bool _full):Deliverable(texture, false), full(_full)
{
}

void Verre::update()
{
    if(full)
    {
        setTexture(&AssetManager::getTexture("../ressource/Bronx/martini_plein.png"));
    }
    Deliverable::update();
}

bool Verre::isFull()
{
    return full;
}

void Verre::setFull(bool val)
{
    full=val;
    AssetManager::playSound("../ressource/audio/bing.wav",20);
}

bool Verre::isUnderShaker(const sf::Vector2f& point)
{
    return (getPosition().x <= point.x && point.x <= getPosition().x+getSize().x && getPosition().y>=point.y /*&& point.y>=getPosition().y-200*/);
}

void Verre::onRelease()
{
    Deliverable::onRelease();
    if(isStored())
        AssetManager::playSound("../ressource/audio/bing.wav",20);
}
