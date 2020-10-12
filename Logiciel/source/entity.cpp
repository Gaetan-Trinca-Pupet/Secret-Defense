#include "header/entity.h"

Entity::Entity(const sf::Vector2f & pos, const sf::Vector2f & size, sf::RenderWindow* w, const sf::Sprite & s)
    : rect(pos, size), window(w), sprite(s)
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
