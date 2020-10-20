#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

///
/// \brief The Entity class is a class allowing to have a sprite with a position and a size
///

class Entity : public sf::Drawable
{
protected:
    sf::Vector2f pos;
    sf::Vector2f size;
private:
    sf::Shape* sprite;
public:
    Entity(const sf::Vector2f & p = sf::Vector2f(), const sf::Vector2f & s = sf::Vector2f(), sf::Shape* sp = nullptr);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    virtual ~Entity();
    void setPos(const sf::Vector2f & p);
    const sf::Vector2f & getPos();
    void setSize(const sf::Vector2f & s);
    const sf::Vector2f & getSize();
    void setSprite(sf::Shape* sp);
    sf::Shape* getSprite ();

    bool operator < (Entity& e);
};

#endif // ENTITY_H
