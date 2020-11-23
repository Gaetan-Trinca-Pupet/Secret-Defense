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
    //delete jeu;

    unsigned int lastPlayed=0; //pour éviter que le même mini jeu soit joué 2 fois d'affilée

    while(true)
    {
        if (app.lives==0)
        {
            app.selecteur=0;
        }
        else
        {
            app.selecteur=rand()%(4-1+1)+1;

            while (app.selecteur==lastPlayed)
            {
                app.selecteur=rand()%(2-1+1)+1;
            }
        }
        switch (app.selecteur){
        case 0:
        {
            gameOverWindow fenetreGameOver(app);
            fenetreGameOver.play();
            break;
        }

        case 1:
        {
            std::cout<<"playing trans1!"<<endl;
            transdata.text.setString("Transition du mini jeu 1\nSuite du texte"); //obligatoire chaque fois qu'on crée une nouvelle transition pour un mini jeu
            transdata.text.setPosition(transdata.text.getPosition().x-transdata.text.getGlobalBounds().width/2, transdata.text.getPosition().y); //pour afficher au centre, toujours ajouter cette ligne pour la transition de n'importe quel minijeu !!après le setstring!!
            transdata.colorText=sf::Color(sf::Color::Red); //pas obligatoire, blanc par défaut !attention! après le premier mini jeu joué, la couleur reste la couleur définie par le mini jeu précédent
            transition trans1(app,transdata);
            trans1.play();
            miniJeuQ thefirst(app);
            std::cout<<"playing thefirst!"<<std::endl;
            thefirst.play();
            transdata.text.setPosition(transdata.text.getPosition().x+transdata.text.getGlobalBounds().width/2, transdata.text.getPosition().y); //obligatoire pour restituer la place enlevée avant, à mettre avant le break à chaque mini jeu
            lastPlayed=1; //à mettre avant chaque break, remplacer 1 par le numéro du case
            break;
        }

        case 2:
        {
            std::cout<<"playing trans2!"<<endl;
            transdata.text.setString("Transition du mini jeu 2\nSuite du texte");
            transdata.text.setPosition(transdata.text.getPosition().x-transdata.text.getGlobalBounds().width/2, transdata.text.getPosition().y);
            transdata.colorText=sf::Color(sf::Color::Blue);
            transition trans2(app,transdata);
            trans2.play();
            miniJeuQ thesecond(app);
            std::cout<<"playing thesecond!"<<std::endl;
            thesecond.play();
            transdata.text.setPosition(transdata.text.getPosition().x+transdata.text.getGlobalBounds().width/2, transdata.text.getPosition().y);
            lastPlayed=2;
            break;
        }

        case 3:
        {
            std::cout<<"playing trans3!"<<endl;
            transdata.text.setString("Transition du mini jeu 3\nSuite du texte");
            transdata.text.setPosition(transdata.text.getPosition().x-transdata.text.getGlobalBounds().width/2, transdata.text.getPosition().y);
            transdata.colorText=sf::Color(sf::Color::Magenta);
            transition trans3(app,transdata);
            trans3.play();
            miniJeuQ thethird(app);
            std::cout<<"playing thethird!"<<std::endl;
            thethird.play();
            transdata.text.setPosition(transdata.text.getPosition().x+transdata.text.getGlobalBounds().width/2, transdata.text.getPosition().y);
            lastPlayed=3;
            break;
        }

        case 4:
        {
            std::cout<<"playing trans4!"<<endl;
            transdata.text.setString("Transition du mini jeu 4\nSuite du texte");
            transdata.text.setPosition(transdata.text.getPosition().x-transdata.text.getGlobalBounds().width/2, transdata.text.getPosition().y);
            transdata.colorText=sf::Color(sf::Color::Yellow);
            transition trans4(app,transdata);
            trans4.play();
            miniJeuQ thefourth(app);
            std::cout<<"playing thefourth!"<<std::endl;
            thefourth.play();
            transdata.text.setPosition(transdata.text.getPosition().x+transdata.text.getGlobalBounds().width/2, transdata.text.getPosition().y);
            lastPlayed=4;
            break;
        }

        }
    }

    return 0;
}
