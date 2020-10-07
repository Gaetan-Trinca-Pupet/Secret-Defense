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

void BranchePC::Prise::setSprite(const sf::Texture & texture)
{
	this->texture = texture;
	sprite.setTexture(this->texture);
	sprite.setTextureRect(sf::IntRect(0, 50, 50, 600));
	if (match != nullptr)
	{
		match->setSprite(this->texture);
		match->sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	}
}

void BranchePC::Prise::setSpriteRect(const unsigned short& x1, const unsigned short& y1, const unsigned short& x2, const unsigned short& y2)
{
	sprite.setTextureRect(sf::IntRect(x1, y1, x2, y2));
}

void BranchePC::Prise::update()
{
	if (this->isClose())
	{
		isMatched = true;
		sprite.setTextureRect(sf::IntRect());
		match->sprite.setTextureRect(sf::IntRect(50, 0, 50, 600));
	}
		
}

void BranchePC::Prise::draw(sf::RenderWindow& window)
{
	sprite.setPosition(x - sX / 2, y - sY / 2);
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