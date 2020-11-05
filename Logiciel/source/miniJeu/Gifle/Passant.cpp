#include "../../../header/miniJeu/Gifle/Gifle.h"
#include <iostream>



Passant::Passant(const sf::Vector2f& pos, sf::RenderWindow* w, float _dir, float* _deltaTime)
	:Clickable(pos, sf::Vector2f(), w)
{
	deltaTime = _deltaTime;
	dir = _dir;
	isGifle = false;
	speed = 110;
	speed += (float(rand()) / float(RAND_MAX) - 0.5) * float(speed * 0.3);
	
	sf::RectangleShape* rect = new sf::RectangleShape(sf::Vector2f(175, 500));
	rect->setFillColor(sf::Color::Blue);
	rect->setOutlineColor(sf::Color::Green);
	rect->setOutlineThickness(4);
	setSprite(rect);

	size = sf::Vector2f(175, 175);

}

Passant::~Passant() {

}

void Passant::update() {
	pos.x += dir * speed * (*deltaTime);
}

bool Passant::isOutOfBounds()
{
	return (dir > 0)  && pos.x >   getWindow()->getSize().x + getSprite()->getOutlineThickness()
		|| (dir <= 0) && pos.x < - getSprite()->getOutlineThickness() - size.x;
}

void Passant::actionOnClick() {
	if (isGifle) return;
	isGifle = true;
	speed *= 8;
	std::cout << "comment osez vous" << std::endl;

	//change de sprite;
}

NonMasque::NonMasque(const sf::Vector2f& pos, sf::RenderWindow* w, float _dir, float* _deltaTime) : Passant(pos, w, _dir, _deltaTime){

	getSprite()->setOutlineColor(sf::Color::Red);
}

NonMasque::~NonMasque() {

}

void NonMasque::actionOnClick() {
	if (isGifle) return;
	isGifle = true;
	speed *= 5;
	std::cout << "arg" << std::endl;

	//change de sprite;
}