#ifndef __BOUTONVF_H_
#define __BOUTONVF_H_

#include "../../clickable.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace CorrigeCopie
{
	class BoutonVF : public Clickable
	{
	private:
		bool VF;
		bool beenClicked;

		sf::RectangleShape backSquare;
		
		void actionOnClick();
	public:
		bool isWhat();
		bool hasBeenClicked();

		void update();
		void draw(sf::RenderWindow& window)const;

		BoutonVF(sf::RenderWindow& window, const bool& vf, const unsigned x = 0, const unsigned y = 0, const unsigned short& s = 50);
		~BoutonVF();

	};
}

#endif