#include "../header/button.h"

Button::Button(sf::RenderWindow *w, const sf::Vector2f &size, const sf::Vector2f &pos, const std::string &t, const unsigned short textSize, const sf::Color &col)
    : Clickable(pos, size, w)
{
    font.loadFromFile("../ressource/fonts/OpenSans-Regular.ttf");
    text = sf::Text(t, font, textSize);
    text.setOrigin(sf::Vector2f(text.getLocalBounds().width/2,text.getLocalBounds().height/2));
    text.setPosition(sf::Vector2f(pos.x + size.x/2, pos.y + (size.y - text.getLocalBounds().height) / 2));
    outerRect = sf::RectangleShape(size);
    outerRect.setFillColor(col);
    outerRect.setPosition(pos);
    setSprite(&outerRect);
    innerRect = sf::RectangleShape(sf::Vector2f(size.x-6, size.y-6));
    innerRect.setFillColor(col*sf::Color(128,128,128));
    innerRect.setPosition(sf::Vector2f(pos.x+3, pos.y+3));
    setSprite(&outerRect);
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

void Button::setText(const std::string &s)
{
    text = sf::Text(s, font);
}

void Button::setColor(const sf::Color & c)
{
    outerRect.setFillColor(c);
    innerRect.setFillColor(c * sf::Color(128,128,128));
}
