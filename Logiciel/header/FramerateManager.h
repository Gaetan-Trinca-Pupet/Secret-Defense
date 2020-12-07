#ifndef __FRAMERATE_MANAGER_H
#define __FRAMERATE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

enum FramerateMode{
	eco = 0,
	middle,
	high,
	dyn
};

class FramerateManager{
	private :
		sf::RenderWindow * window;
		sf::Clock clock;
		unsigned short int framecount;
		FramerateMode expectedMode;
		FramerateMode mode;
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