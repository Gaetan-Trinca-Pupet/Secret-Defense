#ifndef CLICKABLE_H
#define CLICKABLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

<<<<<<< HEAD
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
=======
#include "../header/entity.h"

///
/// \brief The Clickable class allows to create an entity with an action if you click on it, and to check if it is clicked or hovered (using the window the clickable is on to know the mouse position)
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
>>>>>>> master
};

#endif // CLICKABLE_H
