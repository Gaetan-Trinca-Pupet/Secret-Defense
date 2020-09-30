#ifndef __MINI_JEU_ETEINDRE_PERSONNAGE_H
#define __MINI_JEU_ETEINDRE_PERSONNAGE_H

#include <SFML/Graphics.hpp>

namespace EteindrePC{
	enum Direction{
		Bas=0,
		Gauche=1,
		Droite=2,
		Haut=3
	};
	
	class Personnage{
		private :
			sf::Vector2f position;
			sf::Sprite sprite;
			sf::Clock clock;
			Direction direction;
			sf::Texture texture;
			unsigned char sprite_x;
			
		public :
			Personnage();
			void update();
			void draw(sf::RenderWindow& window);
	};
}
#endif