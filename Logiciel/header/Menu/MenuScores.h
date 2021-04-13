#ifndef __MENU_MENU_SCORES_H_
#define __MENU_MENU_SCORES_H_

#include <regex>
#include <fstream>
#include <string>

#include <SFML/Graphics.hpp>
#include "MenusEnum.h"
#include "Bouton.h"
#include "../ScoreServer.h"

namespace Menu {
	class MenuScores
	{
	private:
		sf::Text bestScores;
		sf::Text playerScore;
		sf::Text title;
		Bouton boutonRetour;
		sf::RectangleShape cadreBest;
		sf::RectangleShape cadre;
		std::string* playerName;

	public:
		MenuScores(std::string* playerName);
		void draw(sf::RenderWindow& window);
		void setup();
		void update(sf::RenderWindow& window, Menus& menu);
		void setFont(sf::Font& font);
	};
}

#endif