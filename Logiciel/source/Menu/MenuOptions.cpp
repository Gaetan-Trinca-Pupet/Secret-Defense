#include "../../header/Menu/MenuOptions.h"

constexpr unsigned int windowWidth_u = 960;
constexpr unsigned int windowHeight_u = 540;
constexpr const char * options_filename = "../ressource/options/options.txt";

Menu::MenuOptions::MenuOptions(){
	pseudoField.setPosition(sf::Vector2f(windowWidth_u/2-100+120-15,windowHeight_u/2+25));
	pseudoField.setFillColor(sf::Color(128,128,128));
	pseudoField.setSize(sf::Vector2u(200,50));
	pseudoField.setTextSize(24);
	pseudoField.setMaxLength(16);
	
	selecteurFramrateMode.setSize(sf::Vector2f(200,40));
	selecteurFramrateMode.setPosition(sf::Vector2f(480+120-15,75));
	selecteurFramrateMode.pushOption("economique");
	selecteurFramrateMode.pushOption("moyen");
	selecteurFramrateMode.pushOption("performance");
	selecteurFramrateMode.pushOption("dynamique");
	
	selecteurMusiqueOnOff.setSize(sf::Vector2f(75,45));
	selecteurMusiqueOnOff.setPosition(sf::Vector2f(480-120+15,200));
	selecteurMusiqueOnOff.pushOption("On");
	selecteurMusiqueOnOff.pushOption("Off");
	
	bt_valider.setString("valider");
	bt_valider.setSize(sf::Vector2f(100,50));
	bt_valider.setPosition(sf::Vector2f(windowWidth_u/2,450));
	
	text_framerateMode.setString("Mode");
	text_Music.setString("Sons");
	text_pseudo.setString("Pseudo");
	text_framerateMode.setPosition(sf::Vector2f(/*325+15*/480-100,50));
	text_Music.setPosition(sf::Vector2f(/*500-15*/480-100,175));
	text_pseudo.setPosition(sf::Vector2f(/*325+15*/windowWidth_u/2-100,300));
	text_framerateMode.setOutlineColor(sf::Color(0,0,0));
	text_Music.setOutlineColor(sf::Color(0,0,0));
	text_pseudo.setOutlineColor(sf::Color(0,0,0));
	text_framerateMode.setFillColor(sf::Color(127,127,127));
	text_Music.setFillColor(sf::Color(127,127,127));
	text_pseudo.setFillColor(sf::Color(127,127,127));
	text_framerateMode.setOutlineThickness(1);
	text_Music.setOutlineThickness(1);
	text_pseudo.setOutlineThickness(1);
}


void Menu::MenuOptions::setup(AppData& app){
	loadOptions(app);
}

void Menu::MenuOptions::update(sf::RenderWindow& window, Menus& menu, AppData& app){
	pseudoField.update(window);
	selecteurFramrateMode.update(window);
	selecteurMusiqueOnOff.update(window);
	bt_valider.update(window);
	
	if(selecteurMusiqueOnOff.getSelected() == "Off"){
		sf::Listener::setGlobalVolume(0);
	}else{
		sf::Listener::setGlobalVolume(50);
	}
	
	if(bt_valider.isReleased()){
		std::string choix = selecteurFramrateMode.getSelected();
		if(choix == "economique"){
			app.framerateManager.setMode(eco);
		}else if(choix == "moyen"){
			app.framerateManager.setMode(middle);
		}else if(choix == "performance"){
			app.framerateManager.setMode(high);
		}else if(choix == "dynamique"){
			app.framerateManager.setMode(dyn);
		}else{
			app.framerateManager.setMode(dyn);
		}
		choix = selecteurMusiqueOnOff.getSelected();
		if(choix == "Off"){
			sf::Listener::setGlobalVolume(0);
		}else{
			sf::Listener::setGlobalVolume(50);
		}
		storeOptions(app);
		if(pseudoField.getString() == "")pseudoField.setString("anonyme");
		menu=principal;
	}
}

void Menu::MenuOptions::draw(sf::RenderWindow& window){
	window.draw(text_framerateMode);
	window.draw(text_Music);
	window.draw(text_pseudo);
	selecteurFramrateMode.draw(window);
	selecteurMusiqueOnOff.draw(window);
	bt_valider.draw(window);
	pseudoField.draw(window);
}

void Menu::MenuOptions::setFont(sf::Font& f){
	pseudoField.setFont(f);
	selecteurFramrateMode.setFont(f);
	selecteurMusiqueOnOff.setFont(f);
	bt_valider.setFont(f);
	text_framerateMode.setFont(f);
	text_Music.setFont(f);
	text_pseudo.setFont(f);
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
			std::regex reg_music("muted");
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
					selecteurFramrateMode.setSelected("moyen");
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
			}else if(std::regex_search(str,reg_music)){
				std::regex reg_yes("yes");
				if(std::regex_search(str,reg_yes)){
					selecteurMusiqueOnOff.setSelected("Off");
					sf::Listener::setGlobalVolume(0);
				}else{
					selecteurMusiqueOnOff.setSelected("On");
					sf::Listener::setGlobalVolume(50);
				}
			}
		}
	}
	ifs.close();
	app.pseudo = pseudoField.getString();
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
	if(pseudoField.getString().size() != 0){
		app.pseudo = pseudoField.getString();
	}else{
		app.pseudo = "anonyme";
	}
	optionsFile << "pseudo :" << app.pseudo << std::endl;
	optionsFile << "muted : ";
	if(selecteurMusiqueOnOff.getSelected() == "Off"){
		optionsFile << "yes" << std::endl;
	}else{
		optionsFile << "no" << std::endl;
	}
	
	optionsFile.close();
	
}

void Menu::MenuOptions::updateText(){
	pseudoField.updateText();
}