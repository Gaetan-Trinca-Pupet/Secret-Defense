#ifndef CONTROLLABLE_H
#define CONTROLLABLE_H

#include <SFML/Graphics.hpp>

///
/// \brief The Controllable class is supposed to be an entity which can react to the events (but it is not implemented)
///

class Controllable:sf::RectangleShape
{
public:
    Controllable();
    void update(const sf::Event & events);
};

#endif // CONTROLLABLE_H
