#ifndef __MINI_JEU_ETEINDRE_TABLE_H
#define __MINI_JEU_ETEINDRE_TABLE_H

#include <SFML/Graphics.hpp>
#include "CollisionBox.h"

namespace EteindrePC{
	class Table{
		private :
			CollisionBox body;
			
		public :
			Table(const sf::Vector2f& pos_, const sf::Vector2f& size_);
			CollisionBox& getCollisionBox();
			void draw(sf::RenderWindow& window);
	};
}

#endif