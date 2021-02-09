#include "../../header/Menu/Menu.h"

constexpr unsigned int windowWidth_u = 960;
constexpr unsigned int windowHeight_u = 540;

Menu::Connexion::Connexion(){
	pseudoField.setPosition(sf::Vector2f(windowWidth_u/2,windowHeight_u/2));
	pseudoField.setFillColor(sf::Color(128,128,128));
	pseudoField.setSize(sf::Vector2u(200,50));
	pseudoField.setTextSize(14);
}

void Menu::Connexion::setFont(sf::Font& font){
	pseudoField.setFont(font);
}

void Menu::Connexion::update(sf::RenderWindow& window){
	pseudoField.update(window);
}

void Menu::Connexion::draw(sf::RenderWindow& window){
	pseudoField.draw(window);
}

std::string Menu::Connexion::getPseudo()const{
	return pseudoField.getString();
}

void Menu::Connexion::updateText(){
	pseudoField.updateText();
}