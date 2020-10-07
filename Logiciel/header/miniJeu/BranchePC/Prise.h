#ifndef __PRISE_H_
#define __PRISE_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace BranchePC
{
	class Prise
	{
	private:
		Prise* match;
		bool isMatched = false;

		int x;
		int y;

		int sX;
		int sY;

		sf::Sprite sprite;
		sf::Texture texture;

		bool isClose()const;

	public:
		Prise(Prise* prise = nullptr, const int& myX = 0, const int& myY = 0);
		~Prise();

		void setSprite(const sf::Texture& textur);
		void setSpriteRect(const unsigned short& x1 = 0, const unsigned short& y1 = 0, const unsigned short& x2 = 0, const unsigned short& y2 = 0);

		void update();

		void draw(sf::RenderWindow& window);

		int getX()const;
		int getY()const;

		int getsX()const;
		int getsY()const;

		void setX(const int& X);
		void setY(const int& Y);

		Prise* getMatch()const;
	};

}

#endif