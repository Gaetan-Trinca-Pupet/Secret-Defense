#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

///
/// \brief The Entity class is a class allowing to have a sprite with a position and a size
///

class Entity : public sf::Drawable
{
private:
    sf::Vector2f pos;
    sf::Vector2f size;
    sf::Drawable* sprite;
public:
    Entity(const sf::Vector2f & p = sf::Vector2f(), const sf::Vector2f & s = sf::Vector2f(), sf::Drawable* sp = nullptr);

    ///
    /// \brief draw draws the entity on a window
    /// \param target is the window for the entity to be displayed on
    /// \param states is some additionnal parameters that can be used to change the way the entity is displayed
    ///
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    virtual ~Entity();

    ///
    /// \brief setPos sets a new top left position for the entity
    /// \param p is the position to be set to the entity
    ///
    void setPos(const sf::Vector2f & p);

    ///
    /// \brief getPos returns the entity top left position
    /// \return the entity's position
    ///
    const sf::Vector2f & getPos() const;

    ///
    /// \brief setSize sets a new size for the entity
    /// \param s is the new entity size
    ///
    void setSize(const sf::Vector2f & s);

    ///
    /// \brief getSize returns the entity's size
    /// \return the entity's size
    ///
    const sf::Vector2f & getSize() const;

    ///
    /// \brief setSprite sets a new sprite to the entity
    /// \param sp a pointer to the drawable corresponding to the sprite
    ///
    void setSprite(sf::Drawable* sp);

    ///
    /// \brief getSprite returns the entity's sprite
    /// \return the entity's sprite
    ///
    sf::Drawable* getSprite () const;
};

#endif // ENTITY_H
