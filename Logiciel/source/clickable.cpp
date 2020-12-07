#include "../header/clickable.h"

bool Clickable::otherClickableAlreadyClicked = false;

Clickable::Clickable(const sf::Vector2f & pos, const sf::Vector2f & size, sf::RenderWindow* w, sf::Texture* texture) : sf::RectangleShape(size), window(w)
{
    setPosition(pos);
    setTexture(texture);
}

void Clickable::onClick()
{
    if (window == nullptr) return;
    if (!mouseIsAlreadyPressed) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (isHovered() && !otherClickableAlreadyClicked)
            {
                actionOnClick();
                otherClickableAlreadyClicked = true;
            }
            mouseIsAlreadyPressed = true;
        }
    }
    else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        mouseIsAlreadyPressed = false;
        otherClickableAlreadyClicked = false;
    }
}

void Clickable::actionOnClick()
{
    std::cout << "It works !" << std::endl;
}

bool Clickable::isClicked()
{
    if (!mouseIsAlreadyPressed) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (isHovered())
            {
                return true;
            }
            mouseIsAlreadyPressed = true;
        }
    }
    else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) mouseIsAlreadyPressed = false;
    return false;
}

bool Clickable::isHovered()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    return (mousePos.x >= getPosition().x && mousePos.x <= getPosition().x + getSize().x &&
            mousePos.y >= getPosition().y && mousePos.y <= getPosition().y + getSize().y);
}

Clickable::~Clickable()
{
}
