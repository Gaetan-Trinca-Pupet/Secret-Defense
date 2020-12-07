#ifndef __TEST_PROJET_PTUT_H_
#define __TEST_PROJET_PTUT_H_

#include <vector>
#include <cstdlib>
#include <ctime>  

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "../MiniJeu.h"
#include "Spaceship.h"
#include "../../Controles.h"
#include "Invader.h"
#include "Ball.h"
#include "Missile.h"
#include "Spawner.h"
#include "GlitchEffect.h"
#include "InnerInterface.h"
#include "../../Chrono.h"

namespace TestProjetPtut{
	class TestProjetPtut : public MiniJeu{
		
		private :
			Chrono chrono;
			Spaceship spaceship;
			Controles controles;
			std::vector<Invader> invaders;
			std::vector<Ball> balls;
			std::vector<Missile> missiles;
			sf::Texture textureBackground;
			sf::Sprite background;
			Spawner spawner;
			GlitchEffect glitchEffect;
			InnerInterface innerInterface;
			void setup();
			void draw();
			void update();
			
		public :
			TestProjetPtut(AppData& appData);
		
		
	};
}

#endif
