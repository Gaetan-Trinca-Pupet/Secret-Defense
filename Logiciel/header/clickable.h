#ifndef CLICKABLE_H
#define CLICKABLE_H

#include <SFML/Graphics.hpp>
#include <iostream>


///
/// \brief The Clickable class allows to create an entity with an action if you click on it, and to check if it is clicked or hovered (using the window the clickable is on to know the mouse position)
///

class Clickable:public sf::RectangleShape
{
private:
    sf::RenderWindow* window;
    bool mouseIsAlreadyPressed;
    ///
    /// \brief actionOnClick is the action the button will do if it is clicked when onClick is called
    ///
    virtual void actionOnClick();
public:
    ///
    /// \brief Clickable is the constructor for clickable, using its position, its size, the window it will be displayed on, and a drawable
    /// \param pos is the clickable's top left position
    /// \param size is the clickable's size
    /// \param w is the window the clikable will be displayed on
    /// \param sprite is the clickable's sprite
    ///
    Clickable(const sf::Vector2f & pos = sf::Vector2f(), const sf::Vector2f & size = sf::Vector2f(), sf::RenderWindow* w = nullptr, sf::Texture* texture = nullptr);
    ///
    /// \brief onClick checks if the button is clicked and calls actionOnClick if it is
    ///     (if the mouse hasn't been released since the last call of OnClick, it won't call actionOnClick)
    ///
    void onClick();
    ///
    /// \brief isClicked checks if the button is clicked and returns true if it is
    /// \return a boolean telling if the button is clicked
    ///
    bool isClicked();
    ///
    /// \brief isHovered checks if the button is hovered and returns true if it is
    /// \return a boolean tellig if the button is hovered
    ///
    bool isHovered();
    virtual ~Clickable();
};

#endif // CLICKABLE_H
