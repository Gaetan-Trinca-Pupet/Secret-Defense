#include <SFML/Graphics.hpp>

#include "header/miniJeu/MiniJeu.h"
#include "header/miniJeu/BranchePC/BranchePC.h"

int main()
{
    srand(time(NULL));
    AppData app;
    app.window.create(sf::VideoMode(960, 540), "test");
    app.window.setFramerateLimit(60);

    MiniJeu* jeu = new BranchePC::BranchePC(app);
    jeu->play();
    delete jeu;

    return 0;
}

