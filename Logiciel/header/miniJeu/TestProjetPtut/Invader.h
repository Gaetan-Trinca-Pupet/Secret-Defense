#ifndef __TEST_PROJET_PTUT__INVADER_H_
#define __TEST_PROJET_PTUT__INVADER_H_

#include <cmath>
#include <cstdlib>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Ball.h"
#include "Missile.h"
#include "../../AssetManager.h"

namespace TestProjetPtut{
	class Invader{
		private :
			sf::Sprite sprite;
			sf::Vector2f speed;
			float x_sin;
			short int pv;
			sf::Clock cooldown;
			sf::Clock invulnerabilityDuration;
			char signe_speed;
			bool invulnerability;
		public :
			Invader(sf::Vector2f pos = sf::Vector2f(960/2,50));
			void update();
			void draw(sf::RenderWindow& window);
			bool mustBeDestroyed()const;
			bool isKilled()const;
			
			void inflictDamage(const short int damage);
			
			static std::vector<Ball>* balls;
			static std::vector<Missile>* missiles;
	};
}

#endif