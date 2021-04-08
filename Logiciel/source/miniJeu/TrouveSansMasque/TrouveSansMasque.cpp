#include "../../../header/miniJeu/TrouveSansMasque/TrouveSansMasque.h"
#include <iostream>
#include <time.h>

TrouveSansMasque::TrouveSansMasque::TrouveSansMasque(AppData& appData) : MiniJeu(appData)
{
    chrono = Chrono(app.window);
    chrono.setTempsMax(10.5);
    srand(std::time(NULL));

    erreurCpt = app.difficulty == 1 ? 1 : 0;

    timeBetweenWaves = 2.35 - (app.difficulty / (app.difficulty + 1.6)) * 1.2;

    background.setTexture(AssetManager::getTexture("../ressource/TrouveSansMasque/background.png"));

}

TrouveSansMasque::TrouveSansMasque::~TrouveSansMasque()
{
}

void TrouveSansMasque::TrouveSansMasque::draw()
{
    app.window.draw(background);

    for (Passant& e : passants)
    {
        app.window.draw(e);
    }

    app.window.draw(chrono);
}

void TrouveSansMasque::TrouveSansMasque::update()
{
    //Si le temps est écoulé, fin du minijeu
    if (chrono.getTimePassed() > chrono.getTempsMax())
        end(true);

    //si le minijeu viens de commencer ou que le temps entre les vagues est écoulé, en créer une
    if (passants.size() == 0 || clockPourDelaiVagues.getElapsedTime().asSeconds()  > timeBetweenWaves)
    {
        clockPourDelaiVagues.restart();
        creerPassants();

        //trie passant pour que les passants plus loins(plus haut) soit déssinés d'abord
        sort(passants.begin(), passants.end());
    }


    for (int i(passants.size()); i != 0 && passants.size() != 0;)
    {
        --i;
        passants[i].update();

        //si un passant a traversé l'écran
        if (passants[i].isOutOfBounds())
        {

            // si c'est un passant non masqué et non clické
            // ou si il est masqué mais clické et le nombre d'erreurs est dépassé, le joueur a perdu
            if ( (!passants[i].isMasked() && !passants[i].isTrouve()) ||
                 ( passants[i].isMasked() &&  passants[i].isTrouve() && erreurCpt-- <= 0))
            {
                if (!passants[i].isMasked() && !passants[i].isTrouve()) endMsg = "Vous avez raté passant non masqué.";
                else endMsg = "Vous avez clické sur un passant masqué.";
                end(false);
            }

            passants.erase(passants.begin() + i);
        }
    }

    chrono.update();
}

void TrouveSansMasque::TrouveSansMasque::creerPassants()
{

    int numPasdeMasque(rand() % 4); //choix de celui sans masque
    unsigned cpt(0);

    sf::Vector2f pos;

    //haut à gauche
    pos = sf::Vector2f(-200, 100);
    pos.x -= rand() % 100;
    pos.y += rand() % ((int(app.window.getView().getSize().y - 200) / 2) - 10);
    passants.push_back(Passant(pos, &app.window, 1, cpt++ != numPasdeMasque, app.difficulty));
    //bas à gauche
    pos = sf::Vector2f(-200, app.window.getView().getSize().y - 100);
    pos.x -= rand() % 100;
    pos.y -= rand() % ((int(app.window.getView().getSize().y - 200) / 2) + 10);
    passants.push_back(Passant(pos, &app.window, 1,cpt++ != numPasdeMasque, app.difficulty));

    //haut à droite
    pos = sf::Vector2f(app.window.getView().getSize().x + 200, 100);
    pos.x += rand() % 100;
    pos.y += rand() % ((int(app.window.getView().getSize().y - 200) / 2) - 10);
    passants.push_back(Passant(pos, &app.window, -1, cpt++ != numPasdeMasque, app.difficulty));

    //bas à droite
    pos = sf::Vector2f(app.window.getView().getSize().x + 200, app.window.getView().getSize().y - 100);
    pos.x += rand() % 100;
    pos.y -= rand() % ((int(app.window.getView().getSize().y - 200) / 2) + 10);
    passants.push_back(Passant(pos, &app.window, -1, cpt != numPasdeMasque, app.difficulty));


}
