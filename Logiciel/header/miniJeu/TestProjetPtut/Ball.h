#ifndef __TEST_PROJET_PTUT__BALL_H_
#define __TEST_PROJET_PTUT__BALL_H_

#include <SFML/Graphics.hpp>

namespace TestProjetPtut{
	class Ball{
		private :
			sf::Sprite sprite;
			sf::Vector2f direction;
			bool enemy;
			bool killed;
		public :
			Ball(const sf::Vector2f& position = sf::Vector2f(480,50),const sf::Vector2f& dir = sf::Vector2f(0,-1));
			void update();
			void draw(sf::RenderWindow& window);
			void changeDirection();
			const sf::Vector2f& getPosition()const;
			const sf::Rect<float> getGlobalBounds()const;
			bool isEnemy()const;
			bool mustBeDestroyed()const;
			void kill();
			
			static sf::Texture texture;
			static sf::Vector2f positionLimit;
	};
}

#endif