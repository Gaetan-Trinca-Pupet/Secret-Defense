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
    app.difficulty=1; //TODO implémenter la difficulté dans les mini jeux
    app.lives=3;
    if (!app.font.loadFromFile("../ressource/fonts/arial.ttf"))
    {
        std::cout<<"erreur loadFromFile"<<std::endl;
    }

    Gifle gifle(app);
    gifle.play();

    

    return 0;
}
