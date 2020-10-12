#include "header/entity.h"

Entity::Entity(const sf::Vector2f & p, const sf::Vector2f & s, sf::RenderWindow* w, const sf::Sprite & sp)
    : pos(p), size(s), window(w), sprite(sp)
{

}

sf::Window* Entity::getWindow() const
{
    return window;
}

void Entity::setWindow(sf::RenderWindow* w)
{
    window = w;
}
void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

Entity::~Entity()
{
    delete window;
}

void Entity::setPos(const sf::Vector2f & p)
{
    pos = p;
}

const sf::Vector2f &Entity::getPos()
{
    return pos;
}

void Entity::setSize(const sf::Vector2f & s)
{
    size = s;
}

const sf::Vector2f &Entity::getSize()
{
    return size;
}

void Entity::setSprite(const sf::Sprite &sp)
{
    sprite = sp;
}

const sf::Sprite &Entity::getSprite()
{
    return sprite;
}
