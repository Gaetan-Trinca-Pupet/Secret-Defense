#ifndef __TEST_MINIJEU_H_
#define __TEST_MINIJEU_H_

#include <SFML/Graphics.hpp>

#include "MiniJeu.h"

class UnMiniJeu: public MiniJeu{
	private : 
		sf::RectangleShape rectangle;
		sf::Vector2f direction;
	
	public : 
		UnMiniJeu(AppData& appData);
		
		virtual void setup();
		
		virtual void draw();
		virtual void update();
};

#endif