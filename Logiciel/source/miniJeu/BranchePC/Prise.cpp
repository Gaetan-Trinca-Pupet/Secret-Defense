#include "../../../header/miniJeu/BranchePC/Prise.h"

bool BranchePC::Prise::isClose() const
{
	return
		(((x >= match->getX() - match->getsX() / 2) && (x <= match->getX() + match->getsX() / 2)) ||
		((match->getX() >= x - sX / 2) && (match->getX() <= x + sX / 2))) &&
		(((y >= match->getY() - match->getsY() / 2) && (y <= match->getY() + match->getsY() / 2)) ||
		((match->getY() >= y - sY / 2) && (match->getY() <= y + sY / 2)));
}

BranchePC::Prise::Prise(Prise* prise, const int& myX, const int& myY) : Grabbed(myX,myY,50,50)
{
	match = prise;
	x = myX;
}

BranchePC::Prise::~Prise()
{
	delete match;
}

void BranchePC::Prise::setSprite(const sf::Texture & texture)
{
	this->texture = texture;
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 50, 50, 600));
	if (match != nullptr)
	{
		match->setSprite(texture);
		match->sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	}
}

void BranchePC::Prise::setSpriteRect(const unsigned short& x1, const unsigned short& y1, const unsigned short& x2, const unsigned short& y2)
{
	sprite.setTextureRect(sf::IntRect(x1, y1, x2, y2));
}

void BranchePC::Prise::update()
{
	if (isClose())
	{
		isMatched = true;
		sprite.setTextureRect(sf::IntRect());
		match->sprite.setTextureRect(sf::IntRect(50, 0, 50, 600));
	}
		
}

void BranchePC::Prise::draw(sf::RenderWindow& window)
{
	sprite.setPosition(x - size_x / 2, y - size_y / 2);
	window.draw(sprite);
	if (this->match != nullptr) this->match->draw(window);
}

BranchePC::Prise* BranchePC::Prise::getMatch() const
{
	return match;
}