#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable
{
protected:
    sf::Vector2f pos;
    sf::Vector2f size;
    sf::RenderWindow* window;
private:
    sf::Sprite sprite;
public:
    Entity(const sf::Vector2f & p = sf::Vector2f(), const sf::Vector2f & s = sf::Vector2f(), sf::RenderWindow* w = nullptr, const sf::Sprite & sp = sf::Sprite());
    sf::Window* getWindow() const;
    void setWindow(sf::RenderWindow* w);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    virtual ~Entity();
    void setPos(const sf::Vector2f & p);
    const sf::Vector2f & getPos();
    void setSize(const sf::Vector2f & s);
    const sf::Vector2f & getSize();
    void setSprite(const sf::Sprite & sp);
    const sf::Sprite & getSprite ();
};

#endif // ENTITY_H
