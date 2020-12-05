#ifndef __MINIJEU_H_
#define __MINIJEU_H_

#include <SFML/Graphics.hpp>

//toutes les donnees partagees par les minijeux sont dans cette structure

struct AppData{
	sf::RenderWindow window;
    unsigned int difficulty;
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
		
		sf::Color getBackgroundColor()const;
		void setBackgroundColor(const sf::Color& color);
	
	public :
		MiniJeu(AppData& appData);
        void play();
		virtual ~MiniJeu();
};

#endif
