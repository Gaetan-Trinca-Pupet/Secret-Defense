#ifndef __MINIJEU_H_
#define __MINIJEU_H_

#include <SFML/Graphics.hpp>
#include "../AssetManager.h"
#include "../Chrono.h"
#include <iostream>

//toutes les donnees partagees par les minijeux sont dans cette structure

struct AppData{
	sf::RenderWindow window;
    unsigned int difficulty;
    unsigned int lives;
    sf::Font font;
    unsigned int selecteur;
    unsigned int score=0;
};

class MiniJeu{
	private:
		sf::Color backgroundColor;
        sf::Texture coeur;

	protected:
		AppData& app;
		bool isFinished;

		Chrono chrono;
		sf::Clock deltaTimeClock;
		float deltaTime;
		float tempsMax;
		
		virtual void setup();
		virtual void draw()=0;
		virtual void update()=0;
		
		sf::Color getBackgroundColor()const;
        void setBackgroundColor(const sf::Color& color);
        void drawInterface();

	public :
		MiniJeu(AppData& appData);
        void play();
		virtual ~MiniJeu();

};

#endif
