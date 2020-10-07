#ifndef CONTROLLABLE_H
#define CONTROLLABLE_H

#include <SFML/Graphics.hpp>

class Controllable:sf::RectangleShape
{
public:
    Controllable();
    void update(const sf::Event & events);
};

#endif // CONTROLLABLE_H
