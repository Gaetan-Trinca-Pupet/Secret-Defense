#ifndef __PRISE_H_
#define __PRISE_H_

#include <SFML/Graphics.hpp>

class Prise
{
private:
	Prise* match;
	bool isMatched = false;

	int x;
	int y;

	sf::RectangleShape sprite;

public:
	prise(Prise* prise, int& myX = 0, int& myY = 0);
	~prise();

	void setSprite(sf::RectangleShape & shape);
	void update();

	void draw()const;
};

#endif