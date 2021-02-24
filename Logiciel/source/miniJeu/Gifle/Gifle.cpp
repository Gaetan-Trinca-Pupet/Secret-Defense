#include "../../../header/miniJeu/Gifle/Gifle.h"
#include <iostream>
#include <time.h>




Gifle::Gifle::Gifle(AppData& appData) : MiniJeu(appData)
{
    chrono = Chrono(app.window);
    chrono.setTempsMax(17);
    srand(std::time(NULL));

    erreurCpt = app.difficulty == 0 ? 1 : 0;

    timeBetweenWaves = 2.3 - (app.difficulty / (app.difficulty + 1.6)) * 1.6;

    background.setTexture(AssetManager::getTexture("../ressource/Gifle/background.png"));
}

Gifle::Gifle::~Gifle()
{
}

void Gifle::Gifle::draw()
{
    app.window.draw(background);

    for (Passant& e : passants)
    {
        app.window.draw(e);
    }

    app.window.draw(chrono);
}

void Gifle::Gifle::update()
{
    //Si le temps est ?coul?, fin du minijeu
    if (chrono.getTimePassed() > chrono.getTempsMax() )
        isFinished = true;

    //si le minijeu viens de commencer ou que le temps entre les vagues est ?coul?, en cr?er une
    if (passants.size() == 0 || clockPourDelaiVagues.getElapsedTime().asSeconds()  > timeBetweenWaves)
    {
        clockPourDelaiVagues.restart();
        creerPassants();

        //trie passant pour que les passants plus loins(plus haut) soit d?ssin?s d'abord
        sort(passants.begin(), passants.end());
    }


    for (int i(passants.size()); i != 0 && passants.size() != 0;)
    {
        --i;
        passants[i].update();

        //si un passant a travers? l'?cran
        if (passants[i].isOutOfBounds())
        {

            // si c'est un passant non masqu? et non gifl?,
            // ou si il est masqu? mais gifl? et le nombre d'erreur est d?pass?, c'est que le joueur a perdu
            if ( (!passants[i].isMasked() && !passants[i].isGifle()) ||
                 ( passants[i].isMasked() &&  passants[i].isGifle() && erreurCpt-- <= 0))
            {
                app.lives -= 1;
                isFinished = true;
            }

            passants.erase(passants.begin() + i);
        }
    }

    chrono.update();
}

void Gifle::Gifle::creerPassants()
{

    int numPasdeMasque(rand() % 4); //choix de celui sans masque
    unsigned cpt(0);

    sf::Vector2f pos;

    //haut ? gauche
    pos = sf::Vector2f(-200, 100);
    pos.x -= rand() % 100;
    pos.y += rand() % ((int(app.window.getView().getSize().y - 200) / 2) - 10);
    passants.push_back(Passant(pos, &app.window, 1, cpt++ != numPasdeMasque, app.difficulty));
    //bas ? gauche
    pos = sf::Vector2f(-200, app.window.getView().getSize().y - 100);
    pos.x -= rand() % 100;
    pos.y -= rand() % ((int(app.window.getView().getSize().y - 200) / 2) + 10);
    passants.push_back(Passant(pos, &app.window, 1,cpt++ != numPasdeMasque, app.difficulty));

    //haut ? droite
    pos = sf::Vector2f(app.window.getView().getSize().x + 200, 100);
    pos.x += rand() % 100;
    pos.y += rand() % ((int(app.window.getView().getSize().y - 200) / 2) - 10);
    passants.push_back(Passant(pos, &app.window, -1, cpt++ != numPasdeMasque, app.difficulty));

    //bas ? droite
    pos = sf::Vector2f(app.window.getView().getSize().x + 200, app.window.getView().getSize().y - 100);
    pos.x += rand() % 100;
    pos.y -= rand() % ((int(app.window.getView().getSize().y - 200) / 2) + 10);
    passants.push_back(Passant(pos, &app.window, -1, cpt != numPasdeMasque, app.difficulty));


}


