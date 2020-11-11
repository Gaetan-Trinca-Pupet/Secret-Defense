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
#include "../../Textfield.h"

namespace TestProjetPtut{
	class TestProjetPtut : public MiniJeu{
		
		private :
			Spaceship spaceship;
			Controles controles;
			std::vector<Invader> invaders;
			std::vector<Ball> balls;
			sf::Texture textureBackground;
			sf::Sprite background;
			int ccc;
			int h_ccc;
			sf::Clock appInv;
			
			sf::Font font;
			
			Textfield textfield;
			
			void setup();
			void draw();
			void update();
			
		public :
			TestProjetPtut(AppData& appData);
		
		
	};
}

#endif