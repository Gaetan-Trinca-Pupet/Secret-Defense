#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "header/miniJeu/AmphiReponse/AmphiReponse.h"
#include "header/transition.h"
#include "header/testMiniJeu.h"
#include "header/miniJeuQuentin.h"
#include "header/gameOverWindow.h"

using namespace std;

int main()
{
    srand(time(NULL));
    AppData app;
    app.window.create(sf::VideoMode(960, 540), "test");
    app.window.setFramerateLimit(60);
    app.difficulty=1; //TODO implémenter la difficulté dans les mini jeux
    app.lives=3;
    if (!app.font.loadFromFile("../ressource/fonts/arial.ttf"))
    {
        std::cout<<"erreur loadFromFile"<<std::endl;
    }

    transData transdata;
    transdata.text.setFont(app.font);
    transdata.text.setPosition(app.window.getSize().x/2, app.window.getSize().y/6);
    //UnMiniJeu unMiniJeu(app);
    //unMiniJeu.play();
    MiniJeu * jeu = new AmphiReponse::AmphiReponse(app);
    jeu->play();
    delete jeu;

    return 0;
}
