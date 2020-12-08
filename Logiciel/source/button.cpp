#include "../header/button.h"

Button::Button(sf::RenderWindow *w, const sf::Vector2f &size, const sf::Vector2f &pos, const std::string &t, const unsigned short textSize, const sf::Color &col)
    : Clickable(pos, size, w)
{
    if (!font.loadFromFile("../ressource/fonts/OpenSans-Regular.ttf"))
        std::cerr << "Can't load font" << std::endl;
    text.setString(t);
    text.setFont(font);
    text.setCharacterSize(textSize);
    text.setFillColor(sf::Color::Black);
    text.setPosition(sf::Vector2f(pos.x + size.x/2 - text.getLocalBounds().width /2, pos.y + size.y/2 - text.getLocalBounds().height / 2));
    outerRect = sf::RectangleShape(size);
    outerRect.setFillColor(col*sf::Color(128,128,128));
    outerRect.setPosition(pos);
    setPosition(pos);
    innerRect = sf::RectangleShape(sf::Vector2f(size.x-6, size.y-6));
    innerRect.setFillColor(col);
    innerRect.setPosition(sf::Vector2f(pos.x+3, pos.y+3));
}

Button::Button(const Button &button): font(button.font), text(button.text), innerRect(button.innerRect), outerRect(button.outerRect)
{
    text.setFont(font);
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
    text.setFont (font);
    target.draw(text, states);
}

void Button::setText(const std::string &s)
{
    text.setPosition(text.getPosition().x + text.getLocalBounds().width/2, text.getPosition().y + text.getLocalBounds().height/2);
    text.setString(s);
    text.setPosition(text.getPosition().x - text.getLocalBounds().width/2, text.getPosition().y - text.getLocalBounds().height/2);
}

void Button::setColor(const sf::Color & c)
{
    innerRect.setFillColor(c);
    outerRect.setFillColor(c * sf::Color(128,128,128));
}

sf::Color Button::getColor()
{
    return innerRect.getFillColor();
}

Button &Button::operator=(const Button &b)
{
    font = b.font;
    text = b.text;
    innerRect = b.innerRect;
    outerRect = b.outerRect;
    text.setFont(font);
    setWindow(*b.getWindow());
    setPosition(b.getPosition());
}
