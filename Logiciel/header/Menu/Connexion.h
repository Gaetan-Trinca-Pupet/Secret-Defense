#ifndef __MENU_CONNEXION_h_
#define __MENU_CONNEXION_h_

#include <string>

#include <SFML/Graphics.hpp>

#include "../Textfield.h"
#include "Bouton.h"
#include "../AssetManager.h"
#include "MenusEnum.h"

namespace Menu{
	
	class Connexion{
		private :
			Textfield pseudoField;
			Bouton boutonValider;
		public :
			Connexion();
			void setFont(sf::Font& font);
			void update(sf::RenderWindow& window, Menus& menu);
			void updateText();
			void draw(sf::RenderWindow& window);
			std::string getPseudo()const;
		
	};
	
}

#endif