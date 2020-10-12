#include "header/clickable.h"

Clickable::Clickable(const sf::Vector2f & pos, const sf::Vector2f & size, sf::RenderWindow* w, const sf::Sprite & sprite) : Entity(pos, size, w, sprite)
{

}

void Clickable::onClick()
{
    if (window == nullptr) return;
    if (!mouseIsAlreadyPressed) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (isHovered())
            {
                actionOnClick();
            }
            mouseIsAlreadyPressed = true;
        }
    }
    else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) mouseIsAlreadyPressed = false;
}

void Clickable::actionOnClick()
{
    std::cout << "It works !" << std::endl;
}

bool Clickable::isClicked()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    return (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
            mousePos.x >= rect.left && mousePos.x <= rect.left + rect.width &&
            mousePos.y >= rect.left && mousePos.y <= rect.left + rect.width);
}

bool Clickable::isHovered()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    return (mousePos.x >= rect.left && mousePos.x <= rect.left + rect.width &&
            mousePos.y >= rect.left && mousePos.y <= rect.left + rect.width);
}

Clickable::~Clickable()
{

}
