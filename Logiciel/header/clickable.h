#ifndef CLICKABLE_H
#define CLICKABLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Clickable:public sf::RectangleShape
{
private:
    sf::Window* window;
public:
    Clickable(const sf::Vector2f & pos = sf::Vector2f(), const sf::Vector2f & size = sf::Vector2f(), sf::Window* w = nullptr);
    virtual void onClick();
    virtual bool isClicked();
    virtual ~Clickable();
    sf::Window* getWindow() const;
    void setWindow(sf::Window* value);
};

#endif // CLICKABLE_H
