#include "../../header/Menu/MenuOptions.h"

constexpr unsigned int windowWidth_u = 960;
constexpr unsigned int windowHeight_u = 540;
constexpr const char * options_filename = "../ressource/options/options.txt";

Menu::MenuOptions::MenuOptions(){
	pseudoField.setPosition(sf::Vector2f(windowWidth_u/2,windowHeight_u/2));
	pseudoField.setFillColor(sf::Color(128,128,128));
	pseudoField.setSize(sf::Vector2u(200,50));
	pseudoField.setTextSize(14);
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
	loadOptions(app);
}

void Menu::MenuOptions::update(sf::RenderWindow& window, Menus& menu, AppData& app){
	pseudoField.update(window);
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
		storeOptions(app);
		menu=principal;
	}
}

void Menu::MenuOptions::draw(sf::RenderWindow& window){
	selecteurFramrateMode.draw(window);
	bt_valider.draw(window);
	pseudoField.draw(window);
}

void Menu::MenuOptions::setFont(sf::Font& f){
	pseudoField.setFont(f);
	selecteurFramrateMode.setFont(f);
}

void Menu::MenuOptions::loadOptions(AppData& app){
	pseudoField.setString("anonyme");
	std::ifstream ifs(options_filename);
	if(ifs.is_open()){
		while(!ifs.eof()){
			std::string str;
			std::getline(ifs, str);
			std::regex reg_mode("mode");
			std::regex reg_pseudo("pseudo");
			if(std::regex_search(str,reg_mode)){
				std::regex reg_eco("eco");
				std::regex reg_middle("middle");
				std::regex reg_high("high");
				std::regex reg_dyn("dyn");
				if(std::regex_search(str,reg_eco)){
					app.framerateManager.setMode(eco);
					selecteurFramrateMode.setSelected("economique");
				}else if(std::regex_search(str,reg_middle)){
					app.framerateManager.setMode(middle);
					selecteurFramrateMode.setSelected("je sais pas quoi mettre");
				}else if(std::regex_search(str,reg_high)){
					app.framerateManager.setMode(high);
					selecteurFramrateMode.setSelected("performance");
				}else if(std::regex_search(str,reg_dyn)){
					app.framerateManager.setMode(dyn);
					selecteurFramrateMode.setSelected("dynamique");
				}
			}else if(std::regex_search(str,reg_pseudo)){
				try {
					unsigned int offset_substr = str.find_first_of(":")+1;
					pseudoField.setString(str.substr(offset_substr, str.size()-offset_substr));
				} catch(const std::out_of_range& e) {
					pseudoField.setString("anonyme");
				}
			}
		}
	}
}

void Menu::MenuOptions::storeOptions(AppData& app){
	std::string str_framerate_mode("mode : ");
	switch(app.framerateManager.getFramerateMode()){
		case dyn :
			str_framerate_mode += "dyn";
		break;
		case eco :
			str_framerate_mode += "eco";
		break;
		case middle :
			str_framerate_mode += "middle";
		break;
		case high :
			str_framerate_mode += "high";
		break;
	}
	std::ofstream optionsFile;
	optionsFile.open(options_filename);
	optionsFile << str_framerate_mode << std::endl;
	optionsFile << "pseudo :" << (pseudoField.getString().size() != 0?pseudoField.getString():"anonyme") << std::endl;
	optionsFile.close();
	
}

void Menu::MenuOptions::updateText(){
	pseudoField.updateText();
}