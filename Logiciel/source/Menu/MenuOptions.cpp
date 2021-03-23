#include "../../header/Menu/MenuOptions.h"

constexpr unsigned int windowWidth_u = 960;
constexpr unsigned int windowHeight_u = 540;
constexpr const char * options_filename = "../ressource/options/options.txt";

Menu::MenuOptions::MenuOptions(){
	
	selecteurFramrateMode.setSize(sf::Vector2f(200,50));
	selecteurFramrateMode.setPosition(sf::Vector2f(200,75));
	selecteurFramrateMode.pushOption("economique");
	selecteurFramrateMode.pushOption("je sais pas quoi mettre");
	selecteurFramrateMode.pushOption("performance");
	selecteurFramrateMode.pushOption("dynamique");
	bt_valider.getText().setString("valider");
	bt_valider.getBody().setSize(sf::Vector2f(75,15));
	bt_valider.getBody().setPosition(sf::Vector2f(windowWidth_u/2,500));
	bt_valider.getBody().setOrigin(sf::Vector2f(75/2, 15/2));
}


void Menu::MenuOptions::setup(AppData& app){
	loadFramerateMode(app.framerateManager);
}

void Menu::MenuOptions::update(sf::RenderWindow& window, Menus& menu, AppData& app){
	selecteurFramrateMode.update(window);
	bt_valider.update(window);
	if(bt_valider.isReleased()){
		std::string choix = selecteurFramrateMode.getSelected();
		if(choix == "economique"){
			app.framerateManager.setMode(eco);
		}else if(choix == "je sais pas quoi mettre"){
			app.framerateManager.setMode(middle);
		}else if(choix == "performance"){
			app.framerateManager.setMode(high);
		}else if(choix == "dynamique"){
			app.framerateManager.setMode(dyn);
		}else{
			app.framerateManager.setMode(dyn);
		}
		menu=principal;
	}
}

void Menu::MenuOptions::draw(sf::RenderWindow& window){
	selecteurFramrateMode.draw(window);
	bt_valider.draw(window);
}

void Menu::MenuOptions::setFont(sf::Font& f){
	selecteurFramrateMode.setFont(f);
}

void Menu::MenuOptions::loadFramerateMode(FramerateManager& framerateManager){
	std::ifstream ifs(options_filename);
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
					selecteurFramrateMode.setSelected("economique");
				}else if(std::regex_search(str,reg_middle)){
					framerateManager.setMode(middle);
					selecteurFramrateMode.setSelected("je sais pas quoi mettre");
				}else if(std::regex_search(str,reg_high)){
					framerateManager.setMode(high);
					selecteurFramrateMode.setSelected("performance");
				}else if(std::regex_search(str,reg_dyn)){
					framerateManager.setMode(dyn);
					selecteurFramrateMode.setSelected("dynamique");
				}
				break;
			}
		}
	}
}