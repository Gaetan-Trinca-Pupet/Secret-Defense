#ifndef __INNER_INTERFACE_
#define __INNER_INTERFACE_

#include <SFML/Graphics.hpp>

#include "../../AssetManager.h"

namespace TestProjetPtut{
	class InnerInterface{
		private :
			const short int * pv;
		public :
			void draw(sf::RenderWindow& window);
			void setPv(const short int& hp);
	};
}

 #endif