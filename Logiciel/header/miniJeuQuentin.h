#ifndef MINIJEUQUENTIN_H
#define MINIJEUQUENTIN_H

#include <SFML/Graphics.hpp>
#include "miniJeu/MiniJeu.h"
#include "Chrono.h"

class miniJeuQ : public MiniJeu
{
private:
    sf::CircleShape cercle;
    Chrono chrono;
    float time;
    sf::Clock clock;
protected:
    virtual void setup();

    virtual void draw();
    virtual void update();

public:
    miniJeuQ(AppData& appData);
};


#endif // MINIJEUQUENTIN_H
