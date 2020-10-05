#include "../../../header/miniJeu/BranchePC/Prise.h"

Prise::Prise(Prise* prise, int myX, int myY)
{
	this->match = prise;
	this->x = myX;
	this->y = myY;
}

Prise::~Prise()
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
