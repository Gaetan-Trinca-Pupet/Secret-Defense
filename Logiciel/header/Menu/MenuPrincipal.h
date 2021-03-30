#ifndef __MENU_MENU_PRINCIPAL_H_
#define __MENU_MENU_PRINCIPAL_H_

#include <SFML/Graphics.hpp>

#include "Bouton.h"
#include "MenusEnum.h"


namespace Menu{
	class MenuPrincipal{
		private :
			Bouton bt_quitter;
			//Bouton bt_connexion;
			Bouton bt_jouer;
			Bouton bt_options;
		public :
			MenuPrincipal();
			void update(sf::RenderWindow& window, Menus& menu);
			void draw(sf::RenderWindow& window);
			void setFont(sf::Font& font);
	};
}

#endif