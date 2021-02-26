#ifndef __MINIJEU_H_
#define __MINIJEU_H_

#include <iostream>

#include <SFML/Graphics.hpp>

#include "../FramerateManager.h"
#include "../AssetManager.h"

//toutes les donnees partagees par les minijeux sont dans cette structure

/**
*	The AppData struct contains all variables shared by mini games.
*	@author Erwann Lubrano
*/
struct AppData{
	sf::RenderWindow window;
	FramerateManager framerateManager;
    sf::Font font;
	unsigned int score;
    unsigned short int difficulty;
    unsigned short int lives;
    bool fullscreen;
};


/**
*	MiniJeu is the abstract base class for mini games
*	@author Erwann Lubrano
*	@author Quentin Roubin
*/
class MiniJeu{
	private :
		sf::Color backgroundColor;
	protected :
		AppData& app;
		bool isFinished;
		bool over;
		sf::Clock endDelay;
		
		/**
		*	setup is called once at the begining of play.
		*	@author Erwann Lubrano
		*/
		virtual void setup();

		/**
		*	end is called when the minigame has been won or lost.
		*	@author Ugo Larsonneur
		*/
		void end(bool won);
		
		/**
		*	draw is called by play. It contains all graphics computings
		*	@author Erwann Lubrano
		*/
		virtual void draw()=0;
		
		/**
		*	update is called by play.
		*	@author Erwann Lubrano
		*/
		virtual void update() = 0;

		/**
		*	updateOnEnd is called by play when the minigame is won or lost.
		*	@author Erwann Lubrano
		*/
		virtual void updateOnEnd();
		
		/**
		*	@author Quentin Roubin
		*/
		void drawInterface();
		
		/**
		*	getter of backgroundColor
		*	@return the clear color.
		*	@author Quentin Roubin
		*/
		sf::Color getBackgroundColor()const;
		
		/**
		*	@author Erwann Lubrano
		*	@param color : the color to fill when screen is cleared
		*/
		void setBackgroundColor(const sf::Color& color);
	
	public :
	
		/**
		*	Contructor of MiniJeu
		*	@author Erwann Lubrano
		*	@param appData : the object that contains variables shared by all mini games. Must continue exist.
		*/
		MiniJeu(AppData& appData);
		
		/**
		*	Main loop of mini games.
		*	@author Erwann Lubrano
		*/
        void play();
		
		/**
		*	Destructor of MiniJeu
		*	@author Erwann Lubrano
		*/
		virtual ~MiniJeu();
};

#endif
