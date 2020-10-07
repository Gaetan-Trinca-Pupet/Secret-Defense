#include "../../../header/miniJeu/BranchePC/Hand.h"


BranchePC::Hand::Hand(std::vector<Prise*>& tabPrise):tab(&tabPrise)
{
	texture.loadFromFile("../ressource/BranchePC/open_hand.png");
	sprite.setTexture(texture);

	sX = texture.getSize().x/2;
	sY = texture.getSize().y;

	x = 0;
	y = 0;


	isGrabbing = false;

	prise = nullptr;
}

BranchePC::Hand::~Hand()
{
	delete prise;
}

void BranchePC::Hand::update(sf::RenderWindow& window)
{
	x = sf::Mouse::getPosition(window).x;
	y = sf::Mouse::getPosition(window).y;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		
		if (!isGrabbing)
		{
			isGrabbing = true;
			for (unsigned i = 0; i < tab->size() && prise == nullptr; i++)
				if (this->x >= (*tab)[i]->getX() - (*tab)[i]->getsX() / 2 && this->x <= (*tab)[i]->getX() + (*tab)[i]->getsX() / 2 && this->y >= (*tab)[i]->getY() - (*tab)[i]->getsY() / 2 && this->y <= (*tab)[i]->getY() + (*tab)[i]->getsY() / 2)
					prise = (*tab)[i];
		}
		
		if (prise != nullptr)
		{
			prise->setX(x);
			prise->setY(y);
			prise->update();
		}
			
	}
	else
	{
		prise = nullptr;
		isGrabbing = false;
	}
}

void BranchePC::Hand::draw(sf::RenderWindow& window)
{
	sprite.setPosition(x - sX / 2, y - sY / 2);
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		sprite.setTextureRect(sf::IntRect(25, 0, 25, 25));
	else
		sprite.setTextureRect(sf::IntRect(0,0,25,25));
	
	window.draw(sprite);
}

void BranchePC::Hand::setX(const int& X)
{
	x = X;
}

void BranchePC::Hand::setY(const int& Y)
{
	y = Y;
}