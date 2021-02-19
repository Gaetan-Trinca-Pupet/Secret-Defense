#include "../../header/Menu/MenuPrincipal.h"

constexpr unsigned int windowWidth_u = 960;
constexpr unsigned int windowHeight_u = 540;
constexpr unsigned int boutonWidth_u = 400;
constexpr unsigned int boutonHeight_u = 50;

Menu::MenuPrincipal::MenuPrincipal(){
	bt_quitter.setValue(Menus::quitter);
	bt_connexion.setValue(Menus::connexion);
	bt_jouer.setValue(Menus::jeu);
	bt_options.setValue(Menus::options);
	
	bt_quitter.getText().setString("Quitter");
	bt_connexion.getText().setString("Se connecter");
	bt_jouer.getText().setString("Jouer");
	bt_options.getText().setString("Options");
	
	bt_jouer.getBody().setSize(sf::Vector2f(boutonWidth_u,boutonHeight_u));
	bt_connexion.getBody().setSize(sf::Vector2f(boutonWidth_u,boutonHeight_u));
	bt_options.getBody().setSize(sf::Vector2f(boutonWidth_u,boutonHeight_u));
	bt_quitter.getBody().setSize(sf::Vector2f(boutonWidth_u,boutonHeight_u));
	
	bt_connexion.getBody().setPosition(sf::Vector2f(windowWidth_u-boutonWidth_u/2-2,boutonHeight_u/2 + 2));
	bt_jouer.getBody().setPosition(sf::Vector2f(windowWidth_u/2,100));
	bt_options.getBody().setPosition(sf::Vector2f(windowWidth_u/2,250));
	bt_quitter.getBody().setPosition(sf::Vector2f(windowWidth_u/2,400));
	
	bt_connexion.getBody().setOrigin(sf::Vector2f(boutonWidth_u/2, boutonHeight_u/2));
	bt_jouer.getBody().setOrigin(sf::Vector2f(boutonWidth_u/2, boutonHeight_u/2));
	bt_options.getBody().setOrigin(sf::Vector2f(boutonWidth_u/2, boutonHeight_u/2));
	bt_quitter.getBody().setOrigin(sf::Vector2f(boutonWidth_u/2, boutonHeight_u/2));
}

void Menu::MenuPrincipal::update(sf::RenderWindow& window, Menus& menu){
	bt_quitter.update(window);
	bt_connexion.update(window);
	bt_jouer.update(window);
	bt_options.update(window);
	
	if(bt_quitter.isReleased())menu = bt_quitter.getValue();
	if(bt_connexion.isReleased())menu = bt_connexion.getValue();
	if(bt_jouer.isReleased())menu = bt_jouer.getValue();
	if(bt_options.isReleased())menu = bt_options.getValue();
}

void Menu::MenuPrincipal::draw(sf::RenderWindow& window){
	bt_quitter.draw(window);
	bt_connexion.draw(window);
	bt_jouer.draw(window);
	bt_options.draw(window);
}

void Menu::MenuPrincipal::setFont(sf::Font& font){
	bt_quitter.getText().setFont(font);
	bt_connexion.getText().setFont(font);
	bt_jouer.getText().setFont(font);
	bt_options.getText().setFont(font);
	
	bt_quitter.updateText();
	bt_connexion.updateText();
	bt_jouer.updateText();
	bt_options.updateText();
}