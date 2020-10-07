#ifndef __PRISE_H_
#define __PRISE_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../../Grabber.hpp"

namespace BranchePC
{
	class Prise : public Grabber::Grabbed
	{
	private:
		Prise* match;
		bool isMatched = false;

		sf::Sprite sprite;
		sf::Texture texture;

		bool isClose()const;

	public:
		Prise(Prise* prise = nullptr, const int& myX = 0, const int& myY = 0);
		~Prise();

		void setSprite(const sf::Texture& textur);
		void setSpriteRect(const unsigned short& x1 = 0, const unsigned short& y1 = 0, const unsigned short& x2 = 0, const unsigned short& y2 = 0);

		virtual void update();

		void draw(sf::RenderWindow& window);

		Prise* getMatch()const;
	};

}

#endif