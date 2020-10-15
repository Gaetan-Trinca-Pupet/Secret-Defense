#include "../header/clickable.h"
<<<<<<< HEAD
Clickable::Clickable(const sf::Vector2f & pos, const sf::Vector2f & size, sf::Window* w) : window(w)
{
    setPosition(pos);
    setSize(size);
}

sf::Window* Clickable::getWindow() const
{
    return window;
}

void Clickable::setWindow(sf::Window* w)
{
    window = w;
}

void Clickable::onClick()
{
    if (window == nullptr) return;
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    std::cout<<mousePos.x << ' ' << mousePos.y << std::endl;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&
            mousePos.x >= this->getPosition().x && mousePos.x <= this->getPosition().x + this->getSize().x &&
            mousePos.y >= this->getPosition().y && mousePos.y <= this->getPosition().y + this->getSize().y)
        std::cout << "briz"<< std::endl;
}

bool Clickable::isClicked()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    return (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
            mousePos.x >= this->getPosition().x && mousePos.x <= this->getPosition().x + this->getSize().x &&
            mousePos.y >= this->getPosition().y && mousePos.y <= this->getPosition().y + this->getSize().y);
=======

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
>>>>>>> master
}

Clickable::~Clickable()
{

}
