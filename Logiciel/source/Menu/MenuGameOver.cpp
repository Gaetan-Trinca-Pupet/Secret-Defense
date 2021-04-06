#include "../../header/Menu/MenuGameOver.h"


constexpr unsigned int windowWidth_u = 960;
constexpr unsigned int windowHeight_u = 540;


Menu::MenuGameOver::MenuGameOver(){
	bt_rejouer.setPosition(sf::Vector2f(windowWidth_u/2-150,windowHeight_u/2));
	bt_retour.setPosition(sf::Vector2f(windowWidth_u/2+150,windowHeight_u/2));
	bt_rejouer.setSize(sf::Vector2f(150, 50));
	bt_retour.setSize(sf::Vector2f(150, 50));
	bt_rejouer.setString("Rejouer");
	bt_retour.setString("Menu");
}

void Menu::MenuGameOver::update(sf::RenderWindow& window, Menus& menu){
	bt_rejouer.update(window);
	bt_retour.update(window);
	if(bt_rejouer.isReleased())menu = jeu;
	if(bt_retour.isReleased())menu = principal;
}

void Menu::MenuGameOver::draw(sf::RenderWindow& window){
	bt_rejouer.draw(window);
	bt_retour.draw(window);
}

void Menu::MenuGameOver::setFont(sf::Font& f){
	bt_rejouer.setFont(f);
	bt_retour.setFont(f);
}
