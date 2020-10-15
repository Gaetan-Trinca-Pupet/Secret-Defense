#ifndef BUTTON_H
#define BUTTON_H

#include "../header/clickable.h"

///
/// \brief The Button class is supposed to be a clickable that displays a string easily modifiable (but it is not implemented)
///

class Button:public Clickable
{
private:
    sf::Font font;
    sf::Text text;
    sf::RectangleShape innerRect;
    sf::RectangleShape outerRect;
    virtual void actionOnClick();
public:
    Button(const std::string & t = std::string(), const sf::Color & col = sf::Color(), const sf::Vector2f & pos = sf::Vector2f(), const sf::Vector2f & size = sf::Vector2f(), sf::RenderWindow* w = nullptr);
    virtual ~Button();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif // BUTTON_H
