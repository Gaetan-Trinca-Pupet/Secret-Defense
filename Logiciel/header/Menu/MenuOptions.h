#ifndef __MENU_MENU_OPTIONS_H_
#define __MENU_MENU_OPTIONS_H_

#include <regex>
#include <fstream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../miniJeu/MiniJeu.h"
#include "../miniJeu/MiniJeuManager.h"
#include "MenusEnum.h"
#include "Selecteur.h"
#include "Bouton.h"
#include "../Textfield.h"

namespace Menu{
	class MenuOptions{
		private :
			Textfield pseudoField;
			Selecteur selecteurFramrateMode;
			Selecteur selecteurMusiqueOnOff;
			Bouton bt_valider;
			
			sf::Text text_framerateMode;
			sf::Text text_Music;
			sf::Text text_pseudo;
			
		public :
			MenuOptions();
			void update(sf::RenderWindow& window, Menus& menu, AppData& app);
			void draw(sf::RenderWindow& window);
			void setFont(sf::Font& f);
			void loadOptions(AppData& app);
			void storeOptions(AppData& app);
			void setup(AppData& app);
			void updateText();
	};
}

#endif