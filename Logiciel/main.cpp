#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "header/miniJeu/AmphiReponse/AmphiReponse.h"
#include "header/miniJeu/miniJeu.h"

using namespace std;

int main()
{
    srand(time(NULL));
    AppData app;
    app.window.create(sf::VideoMode(960, 540), "test");
    app.window.setFramerateLimit(60);

    MiniJeu* jeu = new AmphiReponse::AmphiReponse(app);
    jeu->play();
    delete jeu;

    return 0;
}
