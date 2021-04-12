#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <regex>

#include <SFML/Graphics.hpp>

#include "header/Menu/Menu.h"

#include "header/miniJeu/FactoryMiniJeu.h"
#include "header/miniJeu/MiniJeu.h"
#include "header/miniJeu/MiniJeuManager.h"

using namespace std;



int main()
{
    srand(time(NULL));
    AppData app;
    app.window.create(sf::VideoMode(960, 540), "test");
    app.framerateManager.setWindow(app.window);
    app.difficulty=0;
    app.score=0;
    app.lives=3;
    if (!app.font.loadFromFile("../ressource/fonts/OpenSans-Regular.ttf"))
    {
        std::cout<<"erreur loadFromFile"<<std::endl;
    }
	if(!app.mainMusique.openFromFile("../ressource/audio/etapes/minijeu1.wav"))
        std::cerr<<"erreur openFromFile audio"<<std::endl;
    app.mainMusique.setVolume(30);
    app.mainMusique.setLoop(true);
    app.mainMusique.play();
	Menu::Menu menu(app);
	while(menu.getMenu() != Menu::Menus::quitter && app.window.isOpen()){
		menu.play();
		if(menu.getMenu() == Menu::Menus::jeu){
			MiniJeuManager manager(app);
			manager.play();
			menu.setMenu(Menu::Menus::gameOver);
		}
	}

    return 0;
}
