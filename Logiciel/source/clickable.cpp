#include "../header/clickable.h"


Clickable::Clickable(const sf::Vector2f& pos, const sf::Vector2f& size, sf::RenderWindow* w, sf::Shape* sprite) : Entity(pos, size, sprite), window(w)
{
    mouseIsAlreadyPressed = false;
}

bool Clickable::onClick()
{
    bool isClicked = false;

    if (window == nullptr) return false;
    if (!mouseIsAlreadyPressed) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (isHovered())
            {
                actionOnClick();
                isClicked = true;
            }
            mouseIsAlreadyPressed = true;
        }
    }
    else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) mouseIsAlreadyPressed = false;

    return isClicked;
}

void Clickable::actionOnClick()
{
    std::cout << "It works !" << std::endl;
}

bool Clickable::isClicked()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    return (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
            mousePos.x >= pos.x && mousePos.x <= pos.x + size.x &&
            mousePos.y >= pos.y && mousePos.y <= pos.y + size.y);
}

bool Clickable::isHovered()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    return (mousePos.x >= pos.x && mousePos.x <= pos.x + size.x &&
            mousePos.y >= pos.y && mousePos.y <= pos.y + size.y);
}

sf::Window* Clickable::getWindow() const
{
    return window;
}

void Clickable::setWindow(sf::RenderWindow* w)
{
    window = w;
}

Clickable::~Clickable()
{

}
