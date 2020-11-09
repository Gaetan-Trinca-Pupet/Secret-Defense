#include "../../../header/miniJeu/BranchePC/Prise.h"

bool BranchePC::Prise::isClose() const
{
	return
		(((x >= match->getX() - match->getSizeX() / 2) && (x <= match->getX() + match->getSizeX() / 2)) ||
		((match->getX() >= x - size_x / 2) && (match->getX() <= x + size_x / 2))) &&
		(((y >= match->getY() - match->getSizeY() / 2) && (y <= match->getY() + match->getSizeY() / 2)) ||
		((match->getY() >= y - size_y / 2) && (match->getY() <= y + size_y / 2)));
}

BranchePC::Prise::Prise(Prise* prise, const int& myX, const int& myY) : Grabbable(myX,myY,50,50)
{
	match = prise;

	sound.loadFromFile("../ressource/BranchePC/correct.wav");
	sound_plugged.setBuffer(sound);
	sound_plugged.setVolume(5);
	sound_plugged.setPitch(4);
}

BranchePC::Prise::~Prise()
{
	delete match;
}

void BranchePC::Prise::setSprite(const sf::Texture& textur)
{
	texture = textur;
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

void BranchePC::Prise::GrabbableUpdate()
{
	if (isClose() && !isItMatched)
	{
		sound_plugged.play();
		isItMatched = true;
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

bool BranchePC::Prise::isMatched()const
{
	return this->isItMatched;
}

BranchePC::Prise* BranchePC::Prise::getMatch() const
{
	return match;
}
