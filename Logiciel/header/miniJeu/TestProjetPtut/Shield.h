#ifndef __TEST_PROJET_PTUT__SHIELD_H_
#define __TEST_PROJET_PTUT__SHIELD_H_

#include <vector>

#include <SFML/Graphics.hpp>

#include "Ball.h"

namespace TestProjetPtut{
	class Shield{
		private :
			sf::Sprite sprite;
			sf::Texture texture;
			const sf::Vector2f * position;
			std::vector<Ball> * balls;
			sf::Clock cooldown;
			sf::Clock damageCooldown;
			sf::Clock animationClock;
			short int pv;
			bool active;
			
		public :
			Shield();
			void update();
			void draw(sf::RenderWindow& window);
			void bindPosition(const sf::Vector2f& pos);
			void turnOnOff();
			void setBalls(std::vector<Ball> * tabBall);
			bool isActive()const;
	};
}

#endif
 