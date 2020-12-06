#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "header/miniJeu/MiniJeu.h"
#include "header/miniJeu/Gifle/Gifle.h"

using namespace std;

int main()
{
    srand(time(NULL));
    AppData app;
    app.window.create(sf::VideoMode(960, 540), "test");
    app.window.setFramerateLimit(60);
    app.difficulty=4;
    app.lives=3;

    Gifle* minijeu(new Gifle(app));

    minijeu->play();

    

    return 0;
}
