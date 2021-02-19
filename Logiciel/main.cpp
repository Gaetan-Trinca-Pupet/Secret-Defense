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
#include "header/miniJeu/Gifle/Gifle.h"

using namespace std;

void loadFramerateMode(FramerateManager& framerateManager){
	std::ifstream ifs("../ressource/options/options.txt");
	if(ifs.is_open()){
		while(!ifs.eof()){
			std::string str;
			std::getline(ifs, str);
			std::regex reg_mode("mode");
			if(std::regex_search(str,reg_mode)){
				std::regex reg_eco("eco");
				std::regex reg_middle("middle");
				std::regex reg_high("high");
				std::regex reg_dyn("dyn");
				if(std::regex_search(str,reg_eco)){
					framerateManager.setMode(eco);
				}else if(std::regex_search(str,reg_middle)){
					framerateManager.setMode(middle);
				}else if(std::regex_search(str,reg_high)){
					framerateManager.setMode(high);
				}else if(std::regex_search(str,reg_dyn)){
					framerateManager.setMode(dyn);
				}
				break;
			}
		}
	}
}

MiniJeu* createGifle(AppData& app)
{
    return new Gifle(app);
}

int main()
{
    srand(time(NULL));
    AppData app;
    app.window.create(sf::VideoMode(960, 540), "test");
    app.framerateManager.setWindow(app.window);
	loadFramerateMode(app.framerateManager);
    app.difficulty=0;
    app.score=0;
    app.lives=3;
    if (!app.font.loadFromFile("../ressource/fonts/OpenSans-Regular.ttf"))
    {
        std::cout<<"erreur loadFromFile"<<std::endl;
    }

	Menu::Menu menu(app);
	while(menu.getMenu() != Menu::Menus::quitter && app.window.isOpen()){
		menu.play();
		if(menu.getMenu() == Menu::Menus::jeu){
			MiniJeuManager manager(app);
			manager.addMiniJeu(createGifle, "Gifle", "DescriptionGifle");
			manager.play("EteindrePC");
			menu.setMenu(Menu::Menus::principal);
		}
	}

    

    return 0;
}
