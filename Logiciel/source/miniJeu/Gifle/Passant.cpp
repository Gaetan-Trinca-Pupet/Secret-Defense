#include "../../../header/miniJeu/Gifle/Gifle.h"
#include <iostream>



Passant::Passant(const sf::Vector2f& pos, sf::RenderWindow* _window, float _dir, bool masque, unsigned difficulty)
	:Clickable(pos, sf::Vector2f(), _window)
{
	masked = masque;
	window = _window;
	dir = _dir;
	gifle = false;
	enFuite = false;
	speed = 2.2 + (difficulty / (difficulty + 1.7)) * 1.8;
	speed += (float(rand()) / float(RAND_MAX) - 0.5) * float(speed * 0.3);

	setFillColor(sf::Color::Transparent);

	std::string prefix = masque ? "../ressource/Gifle/masque" : "../ressource/Gifle/pas_masque";
	sprite.setTexture(AssetManager::getTexture(prefix + std::to_string(rand() % 3) + ".png"));

	sprite.setTextureRect(sf::IntRect(0, 0, sprite.getTextureRect().width / 3, sprite.getTextureRect().height / 2));

	setSize(sf::Vector2f(75, 80));

	

	if (_dir >= 0)
	{
		sprite.setOrigin((sprite.getTextureRect().width / 2 + getSize().x / 2 + 10), 0);
		sprite.setScale(-1, 1);
	}
	else
		sprite.setOrigin(sprite.getTextureRect().width / 2 - getSize().x / 2 + 10, 0);
}

Passant::~Passant()
{
}

void Passant::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite);
	target.draw(sf::RectangleShape(*this));
}

void Passant::update()
{
	onClick();


	if (!(gifle && clockPourDelaiFuite.getElapsedTime().asSeconds() < 0.5))
	{

		move(dir * speed, 0);

		if (clockPourDelaiAnimation.getElapsedTime().asSeconds() > 0.5 / (speed/2) )
		{
			clockPourDelaiAnimation.restart();

			sf::IntRect newTextureRect(sprite.getTextureRect());
			newTextureRect.left = gifle ? newTextureRect.width * 2 : 0;
			sprite.setTextureRect(newTextureRect);

			if (sprite.getTextureRect().top == 0)
			{

				newTextureRect.top += newTextureRect.height;
				sprite.setTextureRect(newTextureRect);
			}
			else
			{
				newTextureRect.top -= newTextureRect.height;
				sprite.setTextureRect(newTextureRect);
			}
		}
	}


	sprite.setPosition(getPosition());
}

bool Passant::isOutOfBounds()
{
	return (dir > 0) && sprite.getPosition().x > window->getSize().x
		|| (dir <= 0) && sprite.getPosition().x <  - sprite.getTextureRect().width;
}

bool Passant::isMasked()
{
	return masked;
}

bool Passant::isGifle()
{
	return gifle;
}

void Passant::actionOnClick()
{
	if (gifle) return;
	gifle = true;
	speed *= 6;

	clockPourDelaiFuite.restart();

	sf::IntRect newTextureRect(sprite.getTextureRect());
	newTextureRect.left += newTextureRect.width;
	newTextureRect.top = 0;
	//newTextureRect.top = app.option.secretMode ? newTextureRect.height : 0;
	sprite.setTextureRect(newTextureRect);
}

bool Passant::operator < (Passant& p2)
{
	return getPosition().y < p2.getPosition().y;
}