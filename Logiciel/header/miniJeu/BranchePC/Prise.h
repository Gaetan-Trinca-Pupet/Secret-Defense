#ifndef __PRISE_H_
#define __PRISE_H_

#include <SFML/Graphics.hpp>


namespace BranchePC
{
	class Prise
	{
	private:
		Prise* match;
		bool isMatched = false;

		int x;
		int y;

		sf::RectangleShape sprite;



	public:
		Prise(Prise* prise = nullptr, const int& myX = 0, const int& myY = 0);
		~Prise();

		void setSprite(sf::RectangleShape& shape);
		void update();

		void draw(sf::RenderWindow& window)const;

		int getX()const;
		int getY()const;

		void setX(const int& X);
		void setY(const int& Y);

		Prise* getMatch()const;
	};

}

#endif