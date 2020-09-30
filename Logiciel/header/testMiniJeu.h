#ifndef __TEST_MINIJEU_H_
#define __TEST_MINIJEU_H_

#include <SFML/Graphics.hpp>

#include "miniJeu/MiniJeu.h"

class UnMiniJeu: public MiniJeu{
	private : 
		sf::RectangleShape rectangle;
		sf::Vector2f direction;
		
	protected :
		virtual void setup();
		
		virtual void draw();
		virtual void update();
	
	public : 
		UnMiniJeu(AppData& appData);
		
		
};

#endif