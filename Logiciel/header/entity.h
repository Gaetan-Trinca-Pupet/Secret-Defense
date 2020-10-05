#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity : sf::Drawable
{
private:
    sf::Vector2f pos;
public:
    Entity(sf::Vector2f p = sf::Vector2f());
    virtual sf::Vector2f getPos() const;
    virtual void draw();
    virtual ~Entity();
};

#endif // ENTITY_H
