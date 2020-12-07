#include "../../../header/miniJeu/BranchePC/Prise.h"

bool BranchePC::Prise::isClose() const
{
	return this->getGlobalBounds().intersects(this->match->getGlobalBounds());
}

BranchePC::Prise::Prise(Prise* prise, const int& myX, const int& myY) : Grabbable(myX,myY,50,50)
{
	match = prise;
/*
	sound.loadFromFile("../ressource/BranchePC/correct.wav");
	sound_plugged.setBuffer(sound);
	sound_plugged.setVolume(5);
	sound_plugged.setPitch(4);*/
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

void BranchePC::Prise::updateOnGrab()
{
	if (isClose() && !isItMatched)
	{
		//sound_plugged.play();
		isItMatched = true;
		sprite.setTextureRect(sf::IntRect());
		match->sprite.setTextureRect(sf::IntRect(50, 0, 50, 600));
	}
		
}

void BranchePC::Prise::draw(sf::RenderWindow& window)
{
	sprite.setPosition(getPosition().x, getPosition().y);
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
