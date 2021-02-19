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
}

bool Verre::isFull()
{
    return full;
}

void Verre::setFull(bool val)
{
    full=val;
}
