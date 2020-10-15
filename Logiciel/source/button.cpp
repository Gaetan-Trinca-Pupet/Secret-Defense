#include "../header/button.h"

Button::Button(const std::string &t, const sf::Color &col, const sf::Vector2f &pos, const sf::Vector2f &size, sf::RenderWindow *w) : Clickable(pos, size, w)
{
    font.loadFromFile("../ressource/fonts/OpenSans-Regular.ttf");
    text = sf::Text(t, font);
    text.setPosition(pos);
    outerRect = sf::RectangleShape(size);
    outerRect.setFillColor(col);
    outerRect.setPosition(pos);
    setSprite(&outerRect);
    innerRect = sf::RectangleShape(sf::Vector2f(size.x-5, size.y-5));
    innerRect.setFillColor(col*sf::Color(128,128,128));
    innerRect.setPosition(pos);
}

Button::~Button()
{

}

void Button::actionOnClick() {
    std::cout << "It works !" << std::endl;
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(outerRect, states);
    target.draw(innerRect, states);
    target.draw(text, states);
}
