#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "header/miniJeu/MiniJeu.h"
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

    unsigned int lastPlayed=0; //pour éviter que le même mini jeu soit joué 2 fois d'affilée

    sf::Texture textureImg;
    sf::Texture textureBg;

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
            sf::Text txt;
            txt.setString("texte de la transition :\n1");
            transition trans1(app,txt);

            //Exemple d'ajout de background et d'image

            /*
            if (!textureBg.loadFromFile("../ressource/image/background.png"))
            {
                std::cout<<"erreur loadFromFile"<<std::endl;
            }
            if (!textureImg.loadFromFile("../ressource/image/laporte.png"))
            {
                std::cout<<"erreur loadFromFile"<<std::endl;
            }
            trans1.setTextureBackGround(textureBg);
            trans1.setTextureImage(textureImg);
            trans1.setPositionImg(sf::Vector2f(app.window.getSize().x/2, app.window.getSize().y-300));
            */

            trans1.play();
            miniJeuQ thefirst(app);
            std::cout<<"playing thefirst!"<<std::endl;
            thefirst.play();
            lastPlayed=1; //à mettre avant chaque break, remplacer 1 par le numéro du case
            break;
        }

        case 2:
        {
            std::cout<<"playing trans2!"<<endl;
            sf::Text txt2;
            txt2.setString("texte de la transition :\n2");
            transition trans2(app,txt2);
            trans2.play();
            miniJeuQ thesecond(app);
            std::cout<<"playing thesecond!"<<std::endl;
            thesecond.play();
            lastPlayed=2;
            break;
        }

        case 3:
        {
            std::cout<<"playing trans3!"<<endl;
            sf::Text txt3;
            txt3.setString("texte de la transition :\n3");
            transition trans3(app,txt3);
            trans3.play();
            miniJeuQ thethird(app);
            std::cout<<"playing thethird!"<<std::endl;
            thethird.play();
            lastPlayed=3;
            break;
        }

        case 4:
        {
            std::cout<<"playing trans4!"<<endl;
            sf::Text txt4;
            txt4.setString("texte de la transition :\n4");
            transition trans4(app,txt4);
            trans4.play();
            miniJeuQ thefourth(app);
            std::cout<<"playing thefourth!"<<std::endl;
            thefourth.play();
            lastPlayed=4;
            break;
        }

        }
    }

    return 0;
}
