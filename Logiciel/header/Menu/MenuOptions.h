#ifndef __MENU_MENU_OPTIONS_H_
#define __MENU_MENU_OPTIONS_H_

#include <regex>

#include <SFML/Graphics.hpp>
#include "../miniJeu/MiniJeu.h"
#include "../miniJeu/MiniJeuManager.h"
#include "MenusEnum.h"
#include "Selecteur.h"
#include "Bouton.h"

namespace Menu{
	class MenuOptions{
		private :
			Selecteur selecteurFramrateMode;
			Bouton bt_valider;
			
		public :
			MenuOptions();
			void update(sf::RenderWindow& window, Menus& menu, AppData& app);
			void draw(sf::RenderWindow& window);
			void setFont(sf::Font& f);
			void loadFramerateMode(FramerateManager& framerateManager);
			void setup(AppData& app);
	};
}

#endif