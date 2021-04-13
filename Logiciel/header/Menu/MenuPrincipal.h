#ifndef __MENU_MENU_PRINCIPAL_H_
#define __MENU_MENU_PRINCIPAL_H_

#include <SFML/Graphics.hpp>

#include "Bouton.h"
#include "MenusEnum.h"
#include "MenuScores.h"


namespace Menu{
	class MenuPrincipal{
		private :
			Bouton bt_quitter;
			Bouton bt_scores;
			Bouton bt_jouer;
			Bouton bt_options;
			MenuScores* menuScores;
		public :
			MenuPrincipal();
			void setMenuScores(MenuScores* menuScores);
			void update(sf::RenderWindow& window, Menus& menu);
			void draw(sf::RenderWindow& window);
			void setFont(sf::Font& font);
	};
}

#endif