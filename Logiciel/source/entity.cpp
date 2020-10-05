#include "header/entity.h"


Entity::Entity(sf::Vector2f p) : pos(p)
{

}

sf::Vector2f Entity::getPos() const
{
    return pos;
}

void Entity::draw()
{

}

Entity::~Entity()
{

}
