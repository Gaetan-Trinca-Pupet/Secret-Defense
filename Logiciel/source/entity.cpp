#include "../header/entity.h"

///
/// \brief Entity::Entity is the constructor for Entity
/// \param p is the position of te entity
/// \param s is the size of the entity
/// \param w is a pointer to the window the entity will be displayed on
/// \param sp is the entity's sprite
///

Entity::Entity(const sf::Vector2f & p, const sf::Vector2f & s, sf::Shape* sp)
    : pos(p), size(s), sprite(sp)
{

}

///
/// \brief Entity::draw draws the sprite at the correct position on the window
/// \param target the window to draw on
/// \param states
///

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sprite->setPosition(pos);
    target.draw(*sprite, states);
}

Entity::~Entity()
{
    delete sprite;
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

void Entity::setSprite(sf::Shape* sp)
{
    sprite = sp;
}

sf::Shape* Entity::getSprite()
{
    return sprite;
}

bool Entity::operator < (Entity& e) {
    return pos.y < e.getPos().y;
}
