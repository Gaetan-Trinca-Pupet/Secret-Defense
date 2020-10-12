#ifndef CLICKABLE_H
#define CLICKABLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "header/entity.h"

class Clickable:public Entity
{
private:
    bool mouseIsAlreadyPressed;
    virtual void actionOnClick();
public:
    Clickable(const sf::Vector2f & pos = sf::Vector2f(), const sf::Vector2f & size = sf::Vector2f(), sf::RenderWindow* w = nullptr, const sf::Sprite & sprite = sf::Sprite());
    void onClick();
    bool isClicked();
    bool isHovered();
    virtual ~Clickable();
};

#endif // CLICKABLE_H
