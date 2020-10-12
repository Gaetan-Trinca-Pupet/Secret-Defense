#ifndef __MINI_JEU_ETEINDRE_PC_BAS_
#define __MINI_JEU_ETEINDRE_PC_BAS_

#include <SFML/Graphics.hpp>
#include "PC_base.h"

namespace EteindrePC{
	class PC_bas : public PC_base{
		private :
			bool isPersonnageLookingAt();
			void drawWhenIsOn(sf::RenderWindow& window);
			void drawWhenIsOff(sf::RenderWindow& window);
			
		public :
	};
}
#endif