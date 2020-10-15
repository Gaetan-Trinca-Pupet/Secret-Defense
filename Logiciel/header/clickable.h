#ifndef CLICKABLE_H
#define CLICKABLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../header/entity.h"

///
/// \brief The Clickable class allows to create an entity with an action if you click on it, and to check if it is clicked or hovered
///

class Clickable:public Entity
{
private:
    sf::RenderWindow* window;
    bool mouseIsAlreadyPressed;
    virtual void actionOnClick();
public:
    Clickable(const sf::Vector2f & pos = sf::Vector2f(), const sf::Vector2f & size = sf::Vector2f(), sf::RenderWindow* w = nullptr, sf::Drawable* sprite = nullptr);
    sf::Window* getWindow() const;
    void setWindow(sf::RenderWindow* w);
    void onClick();
    bool isClicked();
    bool isHovered();
    virtual ~Clickable();
};

#endif // CLICKABLE_H
