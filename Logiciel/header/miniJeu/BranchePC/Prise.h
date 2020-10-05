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
		sf::RectangleShape sprite;

		bool isClose()const;

	public:
		Prise(Prise* prise = nullptr, const int& myX = 0, const int& myY = 0);
		~Prise();

		/*
		void setSprite(sf::RectangleShape& shape);
		void setColor(const unsigned& r, const unsigned& g, const unsigned& b)const;
		*/
		void update();

		void draw(sf::RenderWindow& window)const;

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