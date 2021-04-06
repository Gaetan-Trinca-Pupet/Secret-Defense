#ifndef __MENU_GAME_OVER_H_
#define __MENU_GAME_OVER_H_

#include <SFML/Graphics.hpp>
#include "MenusEnum.h"
#include "Bouton.h"

namespace Menu{
	class MenuGameOver{
		private :
			Bouton bt_rejouer;
			Bouton bt_retour;
			
		public :
			MenuGameOver();
			void update(sf::RenderWindow& window, Menus& menu);
			void draw(sf::RenderWindow& window);
			void setFont(sf::Font& f);
	};
}

#endif