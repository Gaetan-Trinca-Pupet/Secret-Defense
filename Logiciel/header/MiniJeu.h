#ifndef __MINIJEU_H_
#define __MINIJEU_H_

#include <SFML/Graphics.hpp>

//toutes les donnees partagees par les minijeux sont dans cette structure

struct AppData{
	sf::RenderWindow window;
};

class MiniJeu{
	protected :
		AppData& app;
		bool isFinished;
		sf::Color backgroundColor;
	
	public :
		MiniJeu(AppData& appData);
		virtual void setup();
		virtual void draw()=0;
		virtual void update()=0;
		void play();
		virtual ~MiniJeu();
};

#endif