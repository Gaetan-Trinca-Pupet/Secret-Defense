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
		
		
		sf::Texture texture;
		sf::Sprite sprite;
		sf::RectangleShape backSquare;
		
		void actionOnClick();
	public:
		bool isWhat();
		bool hasBeenClicked();
		void setSpriteText(const sf::Texture texture);

		void update();
		void draw(sf::RenderWindow& window)const;
		
		sf::Sprite getSprite();

		BoutonVF(sf::RenderWindow& window, const bool& vf, const unsigned x = 0, const unsigned y = 0, const unsigned short& s = 50);
		~BoutonVF();

	};
}

#endif