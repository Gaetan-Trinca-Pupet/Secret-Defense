#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable
{
protected:
    sf::Rect<float> rect;
    sf::RenderWindow* window;
private:
    sf::Sprite sprite;
public:
    Entity(const sf::Vector2f & pos = sf::Vector2f(), const sf::Vector2f & size = sf::Vector2f(), sf::RenderWindow* w = nullptr, const sf::Sprite & sp = sf::Sprite());
    sf::Window* getWindow() const;
    void setWindow(sf::RenderWindow* w);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    virtual ~Entity();
};

#endif // ENTITY_H
