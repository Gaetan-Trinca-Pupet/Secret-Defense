#include "../../header/Menu/MenuPrincipal.h"

constexpr unsigned int windowWidth_u = 960;
constexpr unsigned int windowHeight_u = 540;
constexpr unsigned int boutonWidth_u = 400;
constexpr unsigned int boutonHeight_u = 50;

Menu::MenuPrincipal::MenuPrincipal(){
	
	bt_quitter.setString("Quitter");
	bt_scores.setString("Scores");
	bt_jouer.setString("Jouer");
	bt_options.setString("Options");
	
	bt_jouer.setSize(sf::Vector2f(boutonWidth_u,boutonHeight_u));
	bt_options.setSize(sf::Vector2f(boutonWidth_u,boutonHeight_u));
	bt_quitter.setSize(sf::Vector2f(boutonWidth_u, boutonHeight_u));
	bt_scores.setSize(sf::Vector2f(boutonWidth_u, boutonHeight_u));
	
	bt_jouer.setPosition(sf::Vector2f(windowWidth_u/2, 100));
	bt_options.setPosition(sf::Vector2f(windowWidth_u/2,220));
	bt_scores.setPosition(sf::Vector2f(windowWidth_u / 2, 340));
	bt_quitter.setPosition(sf::Vector2f(windowWidth_u / 2, 460));
	
	/*bt_jouer.setOrigin(sf::Vector2f(boutonWidth_u/2, boutonHeight_u/2));
	bt_options.setOrigin(sf::Vector2f(boutonWidth_u/2, boutonHeight_u/2));
	bt_quitter.setOrigin(sf::Vector2f(boutonWidth_u/2, boutonHeight_u/2));*/
	
}

void Menu::MenuPrincipal::setMenuScores(MenuScores* _menuScores)
{
	menuScores = _menuScores;
}

void Menu::MenuPrincipal::update(sf::RenderWindow& window, Menus& menu){
	bt_quitter.update(window);
	bt_jouer.update(window);
	bt_options.update(window);
	bt_scores.update(window);
	
	if (bt_quitter.isReleased())menu = Menus::quitter;
	if (bt_jouer.isReleased())menu = Menus::jeu;
	if (bt_options.isReleased())menu = Menus::options;
	if (bt_scores.isReleased()){
		menuScores->setup();
		menu = Menus::scores;
	}
}

void Menu::MenuPrincipal::draw(sf::RenderWindow& window){
	bt_quitter.draw(window);
	bt_jouer.draw(window);
	bt_options.draw(window);
	bt_scores.draw(window);
}

void Menu::MenuPrincipal::setFont(sf::Font& font){
	bt_quitter.setFont(font);
	bt_jouer.setFont(font);
	bt_options.setFont(font);
	bt_scores.setFont(font);
}