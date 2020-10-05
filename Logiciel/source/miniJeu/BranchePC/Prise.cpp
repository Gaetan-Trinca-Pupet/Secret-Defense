#include "../../../header/miniJeu/BranchePC/Prise.h"

BranchePC::Prise::Prise(Prise* prise, const int& myX, const int& myY)
{
	this->match = prise;
	this->x = myX;
	this->y = myY;
}

BranchePC::Prise::~Prise()
{
	delete match;
}

void BranchePC::Prise::setSprite(sf::RectangleShape& shape)
{
	this->sprite = shape;
}

void BranchePC::Prise::update()
{

}

void BranchePC::Prise::draw(sf::RenderWindow& window) const
{
	sprite.setPosition(this->x, this->y);
	window.draw(sprite);
	if (this->match != nullptr) this->match->draw(window);
}

int BranchePC::Prise::getX() const
{
	return this->x;
}

int BranchePC::Prise::getY() const
{
	return this->y;
}

void BranchePC::Prise::setX(const int & X)
{
	this->x = X;
}

void BranchePC::Prise::setY(const int& Y)
{
	this->y = Y;
}

BranchePC::Prise* BranchePC::Prise::getMatch() const
{
	return this->match;
}

