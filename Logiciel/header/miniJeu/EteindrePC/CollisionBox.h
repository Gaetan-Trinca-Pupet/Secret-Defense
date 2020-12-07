#ifndef __MINI_JEU_ETEINDRE_COLLISION_BOX_H
#define __MINI_JEU_ETEINDRE_COLLISION_BOX_H

#include <SFML/Graphics.hpp>

namespace EteindrePC{
	
	class CollisionBox{
		private :
			sf::Vector2f position;
			sf::Vector2f size;
		public :
			CollisionBox(const sf::Vector2f& pos = sf::Vector2f(), const sf::Vector2f& siz = sf::Vector2f());
			const sf::Vector2f& getPosition()const;
			const sf::Vector2f& getSize()const;
			void setPosition(const sf::Vector2f& pos);
			void setSize(const sf::Vector2f& siz);
	};
	
}

#endif