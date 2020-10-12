#ifndef __MINI_JEU_ETEINDRE_PERSONNAGE_H
#define __MINI_JEU_ETEINDRE_PERSONNAGE_H

#include <vector>
#include <utility>

#include <SFML/Graphics.hpp>
#include "CollisionBox.h"

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
			std::vector<CollisionBox*> collisionList;
			
		public :
			Personnage();
			void update();
			void draw(sf::RenderWindow& window);
			void addCollisionBox(CollisionBox& collisionBox);
			std::pair<sf::Vector2f*,EteindrePC::Direction*> getPersoView();
	};
}
#endif