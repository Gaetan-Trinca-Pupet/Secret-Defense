#include "../../../header/miniJeu/BranchePC/Prise.h"

bool BranchePC::Prise::isClose() const
{
	return
		(((x >= match->getX() - match->getsX() / 2) && (x <= match->getX() + match->getsX() / 2)) ||
		((match->getX() >= x - sX / 2) && (match->getX() <= x + sX / 2))) &&
		(((y >= match->getY() - match->getsY() / 2) && (y <= match->getY() + match->getsY() / 2)) ||
		((match->getY() >= y - sY / 2) && (match->getY() <= y + sY / 2)));
}

BranchePC::Prise::Prise(Prise* prise, const int& myX, const int& myY)
{
	this->match = prise;
	this->x = myX;
	this->y = myY;

	this->sX = 50;
	this->sY = 50;
}

BranchePC::Prise::~Prise()
{
	delete match;
}

/*
void BranchePC::Prise::setSprite(sf::RectangleShape& shape)
{
	this->sprite = shape;
}

void BranchePC::Prise::setColor(const unsigned& r, const unsigned& g, const unsigned& b) const
{
	this->sprite.setFillColor(sf::Color(r, g, b));
}
*/
void BranchePC::Prise::update()
{
	if (this->isClose())
		isMatched = true;
}

void BranchePC::Prise::draw(sf::RenderWindow& window) const
{
	sf::RectangleShape sprit (sf::Vector2f(sX, sY));
	sprit.setPosition(x - sX / 2, y - sY / 2);
	window.draw(sprit);
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

int BranchePC::Prise::getsX() const
{
	return sX;
}

int BranchePC::Prise::getsY() const
{
	return sY;
}

void BranchePC::Prise::setX(const int & X)
{
	if (isMatched)
		x = match->getX();
	else
		this->x = X;
}

void BranchePC::Prise::setY(const int& Y)
{
	if (isMatched)
		y = match->getY() + sY;
	else
		this->y = Y;
}

BranchePC::Prise* BranchePC::Prise::getMatch() const
{
	return this->match;
}