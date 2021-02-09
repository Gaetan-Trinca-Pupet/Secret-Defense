#ifndef __MENU_CONNEXION_h_
#define __MENU_CONNEXION_h_

#include <string>

#include <SFML/Graphics.hpp>

#include "../Textfield.h"

namespace Menu{
	
	class Connexion{
		private :
			Textfield pseudoField;
		public :
			Connexion();
			void setFont(sf::Font& font);
			void update(sf::RenderWindow& window);
			void updateText();
			void draw(sf::RenderWindow& window);
			std::string getPseudo()const;
		
	};
	
}

#endif