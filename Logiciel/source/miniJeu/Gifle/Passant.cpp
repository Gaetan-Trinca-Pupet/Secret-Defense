#include "../../../header/miniJeu/Gifle/Gifle.h"
#include <iostream>



Passant::Passant(const sf::Vector2f& pos, sf::RenderWindow* w, float _dir, bool masque, unsigned difficulty)
	:Clickable(pos, sf::Vector2f(), w)
{
	masked = masque;
	window = w;
	dir = _dir;
	gifle = false;
	speed = 2;
	speed += (float(rand()) / float(RAND_MAX) - 0.5) * float(speed * 0.3);

	sf::RectangleShape* rect = new sf::RectangleShape(sf::Vector2f(175, 500));
	setFillColor(sf::Color::Blue);
	
	if(masked)
		setOutlineColor(sf::Color::Green);
	else
		setOutlineColor(sf::Color::Red);

	setOutlineThickness(4);
	setSize(sf::Vector2f(175, 85));
}

Passant::~Passant()
{
}

void Passant::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::RectangleShape rect(*this);
	rect.setSize(sf::Vector2f(getSize().x, 300));
	target.draw(rect);
}

void Passant::update()
{
	onClick();

	if (!(gifle && clockPourDelaiFuite.getElapsedTime().asSeconds() < 0.3))
		move(dir * speed, 0);
}

bool Passant::isOutOfBounds()
{
	return (dir > 0) && getPosition().x > window->getSize().x + getOutlineThickness()
		|| (dir <= 0) && getPosition().x < -getOutlineThickness() - getSize().x;
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
	speed *= 10;

	clockPourDelaiFuite.restart();

	//change de sprite;
}

bool Passant::operator < (Passant& p2)
{
	return getPosition().y < p2.getPosition().y;
}