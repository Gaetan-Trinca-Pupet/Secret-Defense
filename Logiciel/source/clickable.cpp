#include "header/clickable.h"

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
        actionOnClick();
}

void actionOnClick()
{

}

bool Clickable::isClicked()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    return (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
            mousePos.x >= this->getPosition().x && mousePos.x <= this->getPosition().x + this->getSize().x &&
            mousePos.y >= this->getPosition().y && mousePos.y <= this->getPosition().y + this->getSize().y);
}

Clickable::~Clickable()
{

}
