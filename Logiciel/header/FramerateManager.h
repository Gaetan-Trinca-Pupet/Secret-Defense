#ifndef __FRAMERATE_MANAGER_H
#define __FRAMERATE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

enum FramerateMode : int{
    eco,
    middle,
    high,
    dyn
};

class FramerateManager{
	private :
        FramerateMode expectedMode;
        FramerateMode mode;
		sf::RenderWindow * window;
		sf::Clock clock;
		unsigned short int framecount;
		unsigned short int nbUpdatePerSec;

		struct{
			unsigned int ecomode : 2;
			unsigned int highmode : 1;
			unsigned int middlemode : 1;
		}updatecount;
	public :
		FramerateManager();
		void reset();
		bool mustUpdate();
		void setMode(FramerateMode framerateMode);
		void setWindow(sf::RenderWindow& renderWindow);
		void updateMode();
		
};

#endif
