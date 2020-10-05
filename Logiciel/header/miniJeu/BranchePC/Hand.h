#ifndef __HAND_H_
#define __HAND_H_

#include "Prise.h"
#include <SFML/Window.hpp>
#include <vector>

namespace BranchePC
{
	class Hand
	{
		private :
			std::vector<Prise*>* tab;
			int x;
			int y;

			int sX;
			int sY;

			bool isGrabbing;

			BranchePC::Prise* prise;

		public :
			Hand(std::vector<Prise*>& tabPrise);
			~Hand();

			void update(sf::RenderWindow& window);
			void draw(sf::RenderWindow& window)const;

			void setX(const int& X);
			void setY(const int& Y);
	};
}




#endif