#ifndef BUTTON_H
#define BUTTON_H

#include "../header/clickable.h"

///
/// \brief The Button class is a clickable that displays a string in a rectangle
///

class Button:public Clickable
{
private:
    sf::Font font;
    mutable sf::Text text;
    sf::RectangleShape innerRect;
    sf::RectangleShape outerRect;
    virtual void actionOnClick() override;
public:

    ///
    /// \brief Button::Button is the constructor for Button, which uses the postion, the size, the color,
    ///     the text, its size and the window the button will be displayed on to create the button
    /// \param t is the string to be displayed
    /// \param col is the color of the outer rect of the button (the inner color depends on this color)
    /// \param pos is the top left position of the button
    /// \param size is the button's size
    /// \param w is the window the button will be displayed on
    ///
    Button(sf::RenderWindow* w = nullptr, const sf::Vector2f & size = sf::Vector2f(), const sf::Vector2f & pos = sf::Vector2f(),
           const std::string & t = std::string(), const unsigned short textSize = 20, const sf::Color & col = sf::Color());

    ///
    /// \brief Button is the constructor by copy of button (it copies it and sets the new button's text's font to the new button's font)
    /// \param button the button to copy
    ///
    Button(const Button & button);

    virtual ~Button();

    ///
    /// \brief draw draws the button on a window
    /// \param target is the window for the button to be displayed on
    /// \param states is some additionnal parameters that can be used to change the way the button is displayed
    ///
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    ///
    /// \brief setText sets the text to be displayed
    /// \param s the string corresponding to the button's text
    ///
    void setText(const std::string & s);

    ///
    /// \brief setColor sets the color of the button
    /// \param c is the outer color of the button (the inner one is the same but lighter)
    ///
    void setColor(const sf::Color & c);


    ///
    /// \brief getColor gets the color of the outer rect of the button
    /// \return the color of the outer rect of the button
    ///
    sf::Color getColor();


    ///
    /// \brief operator = is the operator = of the button (it copies it and sets the left button's text's font to the left button's font)
    /// \param b the button to copy
    /// \return the left button
    ///
    Button & operator= (const Button & b);
};

#endif // BUTTON_H
