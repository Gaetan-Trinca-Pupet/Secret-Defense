#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "header/miniJeu/MiniJeu.h"
#include "header/miniJeu/DistribMiniTests/DistribMiniTests.h"

using namespace std;

int main()
{
    srand(time(NULL));
    AppData app;
    app.window.create(sf::VideoMode(960, 540), "test");
    app.window.setFramerateLimit(60);
    app.difficulty = 0;
    app.lives = 3;

    DisitribMiniTests* minijeu(new DisitribMiniTests(app));

    minijeu->play();

    return 0;
}
