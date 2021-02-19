#include "../../header/Menu/Menu.h"

constexpr unsigned int windowWidth_u = 960;
constexpr unsigned int windowHeight_u = 540;

Menu::Connexion::Connexion(){
	pseudoField.setPosition(sf::Vector2f(windowWidth_u/2,windowHeight_u/2));
	pseudoField.setFillColor(sf::Color(128,128,128));
	pseudoField.setSize(sf::Vector2u(200,50));
	pseudoField.setTextSize(14);
	boutonValider.getBody().setSize(sf::Vector2f(70,20));
	boutonValider.getBody().setPosition(sf::Vector2f(50,50));
	boutonValider.enable();
	boutonValider.getText().setString("text");
	boutonValider.setValue(Menus::principal);
}

void Menu::Connexion::setFont(sf::Font& font){
	pseudoField.setFont(font);
	boutonValider.getText().setFont(font);
	boutonValider.updateText();
}

void Menu::Connexion::update(sf::RenderWindow& window, Menus& menu){
	pseudoField.update(window);
	boutonValider.update(window);
	if(boutonValider.isReleased()){
		menu = boutonValider.getValue();
	}
}

void Menu::Connexion::draw(sf::RenderWindow& window){
	pseudoField.draw(window);
	boutonValider.draw(window);
}

std::string Menu::Connexion::getPseudo()const{
	return pseudoField.getString();
}

void Menu::Connexion::updateText(){
	pseudoField.updateText();
}