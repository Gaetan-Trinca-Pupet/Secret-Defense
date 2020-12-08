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
    sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);

    sf::Vector2f mousePos = window->mapPixelToCoords(pixelPos);

    return (getGlobalBounds().contains(mousePos.x, mousePos.y));
}

void Clickable::setWindow(sf::RenderWindow &w)
{
    window = &w;
}

sf::RenderWindow* Clickable::getWindow() const
{
    return window;
}

Clickable::~Clickable()
{
}
