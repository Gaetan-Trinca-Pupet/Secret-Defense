#ifndef __MINI_JEU_ETEINDRE_PC_BASE_
#define __MINI_JEU_ETEINDRE_PC_BASE_

#include <utility>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Personnage.h"

namespace EteindrePC{
	class PC_base{
		private :
			bool alreadyChanged;
		protected :
			sf::Vector2f position;
			bool on;
			std::pair<sf::Vector2f*,EteindrePC::Direction*> persoView;
			virtual bool isPersonnageLookingAt()=0;
			virtual void drawWhenIsOn(sf::RenderWindow& window)=0;
			virtual void drawWhenIsOff(sf::RenderWindow& window)=0;
			
		public :
			bool isOn() const;
			void update();
			void draw(sf::RenderWindow& window);
			void setPersoView(const std::pair<sf::Vector2f*,EteindrePC::Direction*>& pView);
			void setPosition(const sf::Vector2f& pos);
	};
}
#endif