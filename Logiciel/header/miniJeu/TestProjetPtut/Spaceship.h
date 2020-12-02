#ifndef __TEST_PROJET_PTUT__SPACESHIP_H_
#define __TEST_PROJET_PTUT__SPACESHIP_H_

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "../../Controles.h"
#include "Shield.h"
#include "Ball.h"
#include "Missile.h"

namespace TestProjetPtut{
	class Spaceship{
		private :
			sf::Sprite sprite;
			sf::Texture texture;
			Controles * controles;
			Shield shield;
			sf::Vector2f positionLimit;
			std::vector<Ball> * balls;
			std::vector<Missile>* missiles;
			sf::Clock cooldown;
			short int pv;
			constexpr float cooldown_duration(){return 0.1;};
		public :
			Spaceship();
			void bindControles(Controles& contr);
			void setBalls(std::vector<Ball> * tabBall);
			void setMissiles(std::vector<Missile> * tabMissile);
			void setPositionLimit(const sf::Vector2f& pl);
			void draw(sf::RenderWindow& window);
			void update();
			void inflictDamage(const short int damage);
	};
}

#endif