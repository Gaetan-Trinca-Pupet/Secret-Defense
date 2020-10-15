#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H

#include <SFML/Graphics.hpp>
#include "miniJeu/MiniJeu.h"

class gameOverWindow : public MiniJeu
{
private:
    sf::Text text;
    bool isContinuer;
    sf::CircleShape bouton1;
    sf::CircleShape bouton2;
protected:
    virtual void setup();

    virtual void draw();
    virtual void update();

public:
    gameOverWindow(AppData& appData);
};

#endif // GAMEOVERWINDOW_H
