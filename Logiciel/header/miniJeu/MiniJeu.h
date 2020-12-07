#ifndef __MINIJEU_H_
#define __MINIJEU_H_

#include <iostream>

#include <SFML/Graphics.hpp>

#include "../FramerateManager.h"
#include "../AssetManager.h"

//toutes les donnees partagees par les minijeux sont dans cette structure

struct AppData{
	sf::RenderWindow window;
	FramerateManager framerateManager;
	sf::Font font;
	unsigned int score;
    unsigned short int difficulty;
    unsigned short int lives;
    unsigned short int selecteur;
	bool fullscreen;
};

class MiniJeu{
	private :
		sf::Color backgroundColor;
	protected :
		AppData& app;
		bool isFinished;
		
		virtual void setup();
		virtual void draw()=0;
		virtual void update()=0;
		
		void drawInterface();
		
		sf::Color getBackgroundColor()const;
		void setBackgroundColor(const sf::Color& color);
	
	public :
		MiniJeu(AppData& appData);
        void play();
		virtual ~MiniJeu();
};

#endif
