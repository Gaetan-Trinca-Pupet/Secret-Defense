#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "header/miniJeu/MiniJeu.h"
#include "header/transition.h"
#include "header/testMiniJeu.h"
#include "header/miniJeuQuentin.h"
#include "header/gameOverWindow.h"
#include "header/miniJeu/TestProjetPtut/TestProjetPtut.h"

int main()
{
    std::srand(time(nullptr));
    AppData app;
	app.fullscreen = false;
    app.window.create(sf::VideoMode(960, 540), "test");
    app.window.setFramerateLimit(60);
    app.difficulty=3; //TODO implémenter la difficulté dans les mini jeux
    app.lives=0;
    //unMiniJeu.play();
    MiniJeu * jeu = new TestProjetPtut::TestProjetPtut(app);
    jeu->play();
    delete jeu;
    return 0;
}
