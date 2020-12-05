#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "header/miniJeu/MiniJeu.h"
#include "header/miniJeu/CorrigeCopie/CorrigeCopie.h"

using namespace std;

int main()
{
    srand(time(NULL));
    AppData app;
    app.window.create(sf::VideoMode(960, 540), "test");
    app.window.setFramerateLimit(60);


    //UnMiniJeu unMiniJeu(app);
    //unMiniJeu.play();
    MiniJeu* jeu = new CorrigeCopie::CorrigeCopie(app);
    jeu->play();
    delete jeu;

    return 0;
}
