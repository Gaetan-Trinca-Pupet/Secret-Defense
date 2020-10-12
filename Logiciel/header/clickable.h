#ifndef CLICKABLE_H
#define CLICKABLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Clickable:public sf::RectangleShape
{
private:
    sf::RenderWindow* window;
    bool mouseIsAlreadyPressed;
    virtual void actionOnClick();
public:
    Clickable(const sf::Vector2f & pos = sf::Vector2f(), const sf::Vector2f & size = sf::Vector2f(), sf::RenderWindow* w = nullptr);
    void onClick();
    bool isClicked();
    bool isHovered();
    virtual ~Clickable();
    sf::Window* getWindow() const;
    void setWindow(sf::RenderWindow* value);
};

#endif // CLICKABLE_H
