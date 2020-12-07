#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "header/miniJeu/MiniJeu.h"
#include "header/transition.h"
#include "header/testMiniJeu.h"
#include "header/miniJeuQuentin.h"
#include "header/gameOverWindow.h"
#include "header/miniJeu/DistribMiniTests/DistribMiniTests.h"
#include "header/miniJeu/Gifle/Gifle.h"
#include "header/miniJeu/MemoryQuestions/memoryquestions.h"
#include "header/miniJeu/TestProjetPtut/TestProjetPtut.h"
#include "header/miniJeu/EteindrePC/EteindrePC.h"
#include "header/miniJeu/AmphiReponse/AmphiReponse.h"
#include "header/miniJeu/BranchePC/BranchePC.h"
#include "header/miniJeu/CorrectTheCode/CorrectTheCode.h"
#include "header/miniJeu/CorrigeCopie/CorrigeCopie.h"

using namespace std;

int main()
{
    srand(time(NULL));
    AppData app;
    app.window.create(sf::VideoMode(960, 540), "test");
    app.framerateManager.setWindow(app.window);
    app.difficulty=0; //TODO implémenter la difficulté dans les mini jeux
    app.lives=3;
    if (!app.font.loadFromFile("../ressource/fonts/OpenSans-Regular.ttf"))
    {
        std::cout<<"erreur loadFromFile"<<std::endl;
    }

    unsigned int lastPlayed=0; //pour éviter que le même mini jeu soit joué 2 fois d'affilée

    sf::Texture textureImg;
    sf::Texture textureBg;
    unsigned int selecteur;
    unsigned int nbGamesFinished=0;

    while(app.window.isOpen())
    {
        if (app.lives==0)
        {
            selecteur=0;
        }
        else if(nbGamesFinished==5)
        {
            selecteur=99;                   //Remplacer 99 par le numéro du boss, si plusieurs boss faire un rand entre les numéros des boss
        }
        else
        {
            selecteur=rand()%(8-1+1)+1;

            while (selecteur==lastPlayed)
            {
                selecteur=rand()%(8-1+1)+1;
            }
        }
        switch (selecteur){
        case 0:
        {
            nbGamesFinished=0;
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
            trans1.setPositionImg(sf::Vector2f(app.window.getView().getSize().x/2, app.window.getView().getSize().y-300));
            */

            trans1.play();
            EteindrePC::EteindrePC eteindrePC(app);
            std::cout<<"playing thefirst!"<<std::endl;
            eteindrePC.play();
            lastPlayed=1; //à mettre avant chaque break, remplacer 1 par le numéro du case
            nbGamesFinished+=1; //à mettre avant chaque break
            break;
        }

        case 2:
        {
            std::cout<<"playing trans2!"<<endl;
            sf::Text txt2;
            txt2.setString("texte de la transition :\n2");
            transition trans2(app,txt2);
            trans2.play();
            DisitribMiniTests disitribMiniTests(app);
            std::cout<<"playing thesecond!"<<std::endl;
            disitribMiniTests.play();
            lastPlayed=2;
            nbGamesFinished+=1;
            break;
        }

        case 3:
        {
            std::cout<<"playing trans3!"<<endl;
            sf::Text txt3;
            txt3.setString("texte de la transition :\n3");
            transition trans3(app,txt3);
            trans3.play();
            Gifle gifle(app);
            std::cout<<"playing thethird!"<<std::endl;
            gifle.play();
            lastPlayed=3;
            nbGamesFinished+=1;
            break;
        }

        case 4:
        {
            std::cout<<"playing trans4!"<<endl;
            sf::Text txt4;
            txt4.setString("texte de la transition :\n4");
            transition trans4(app,txt4);
            trans4.play();
            memoryQuestions::MemoryQuestions memoryQuestions(app);
            std::cout<<"playing thefourth!"<<std::endl;
            memoryQuestions.play();
            lastPlayed=4;
            nbGamesFinished+=1;
            break;
        }

        case 5:
        {
            std::cout<<"playing trans5!"<<endl;
            sf::Text txt5;
            txt5.setString("texte de la transition :\n5");
            transition trans5(app,txt5);
            trans5.play();
            AmphiReponse::AmphiReponse amphiReponse(app);
            std::cout<<"playing thefifth!"<<std::endl;
            amphiReponse.play();
            lastPlayed=5;
            nbGamesFinished+=1;
            break;
        }

        case 6:
        {
            std::cout<<"playing trans6!"<<endl;
            sf::Text txt6;
            txt6.setString("texte de la transition :\n6");
            transition trans6(app,txt6);
            trans6.play();
            BranchePC::BranchePC branchePC(app);
            std::cout<<"playing thesixth!"<<std::endl;
            branchePC.play();
            lastPlayed=6;
            nbGamesFinished+=1;
            break;
        }

        case 7:
        {
            std::cout<<"playing trans7!"<<endl;
            sf::Text txt7;
            txt7.setString("texte de la transition :\n7");
            transition trans7(app,txt7);
            trans7.play();
            correctthecode::CorrectTheCode correctTheCode(app);
            std::cout<<"playing theseventh!"<<std::endl;
            correctTheCode.play();
            lastPlayed=7;
            nbGamesFinished+=1;
            break;
        }

        case 8:
        {
            std::cout<<"playing trans8!"<<endl;
            sf::Text txt8;
            txt8.setString("texte de la transition :\n8");
            transition trans8(app,txt8);
            trans8.play();
            CorrigeCopie::CorrigeCopie corrigeCopie(app);
            std::cout<<"playing theeighth!"<<std::endl;
            corrigeCopie.play();
            lastPlayed=8;
            nbGamesFinished+=1;
            break;
        }

        case 99:
        {
            std::cout<<"playing trans99!"<<endl;
            sf::Text txt99;
            txt99.setString("texte de la transition :\n99");
            transition trans99(app,txt99);
            trans99.play();
            TestProjetPtut::TestProjetPtut testProjetPtut(app);
            std::cout<<"playing theboss99!"<<std::endl;
            testProjetPtut.play();
            nbGamesFinished=0;
            app.difficulty+=1;
            break;
        }

        }
    }

    return 0;
}
