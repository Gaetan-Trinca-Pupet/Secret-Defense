#ifndef __TEST_PROJET_PTUT__MISSILE_H_
#define __TEST_PROJET_PTUT__MISSILE_H_

#include <SFML/Graphics.hpp>

namespace TestProjetPtut{
	class Missile{
		private :
			constexpr float speed(){return -15.0;};
			sf::RectangleShape rectangleShape;
			bool isKilled;
		public :
			Missile(const sf::Vector2f& position = sf::Vector2f());
			void update();
			void draw(sf::RenderWindow& window);
			bool mustBeDestroyed()const;
			void kill();
			const sf::Vector2f& getPosition()const;
	};
}

#endif