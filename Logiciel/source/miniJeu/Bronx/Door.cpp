#include "../../../header/miniJeu/Bronx/Door.h"

Door::Door(const int& x, const int& y, AppData& app, sf::Texture* texture, bool _opened): Clickable(sf::Vector2f(x,y),sf::Vector2f(texture->getSize().x,texture->getSize().y), &app.window, texture)
{
    setOpened(_opened);
    setTexture(texture);
    setSize(sf::Vector2f(texture->getSize().x,texture->getSize().y));
    setPosition(x, y);
}

bool Door::isOpened()
{
    return opened;
}

void Door::setOpened(bool value)
{
    opened=value;
}

void Door::update()
{
    if(isHovered())
    {
        setFillColor(sf::Color(0,0,0,0));
        setOutlineColor(sf::Color(0,0,0,0));
    }
}
