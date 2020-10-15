#include "../header/clickable.h"

Clickable::Clickable(const sf::Vector2f & pos, const sf::Vector2f & size, sf::RenderWindow* w, sf::Drawable* sprite) : Entity(pos, size, sprite), window(w)
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
            mousePos.x >= getPos().x && mousePos.x <= getPos().x + getSize().x &&
            mousePos.y >= getPos().y && mousePos.y <= getPos().y + getSize().y);
}

bool Clickable::isHovered()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    return (mousePos.x >= getPos().x && mousePos.x <= getPos().x + getSize().x &&
            mousePos.y >= getPos().y && mousePos.y <= getPos().y + getSize().y);
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
    delete window;
}
