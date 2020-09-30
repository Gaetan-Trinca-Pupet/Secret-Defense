#include "../../../header/miniJeu/BranchePC/Prise.h"

Prise::prise(Prise* prise, int& myX, int& myY)
{
	this->match = prise;
	this->x = myX;
	this->y = myY;
}

Prise::~prise()
{
	delete match;
}

void Prise::setSprite(sf::RectangleShape& shape)
{
	this->sprite = shape;
}

void Prise::update()
{

}

void Prise::draw() const
{

}
