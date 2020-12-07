#ifndef __MINI_JEU_ETEINDRE_MUR_H
#define __MINI_JEU_ETEINDRE_MUR_H

#include <SFML/Graphics.hpp>
#include "CollisionBox.h"

namespace EteindrePC{
	class Mur{
		private :
			CollisionBox body;
			
		public :
			Mur(unsigned short int h, unsigned short int l);
			CollisionBox& getCollisionBox();
			void draw(sf::RenderWindow& window);
	};
}

#endif