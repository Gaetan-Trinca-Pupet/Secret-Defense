#include "../../../header/miniJeu/Gifle/Gifle.h"
#include <iostream>


Etudiant::Etudiant(const sf::Vector2f& pos, sf::RenderWindow* w, float _dir, float* _deltaTime)
	:Clickable(pos, sf::Vector2f(), w)
{
	deltaTime = _deltaTime;
	dir = _dir;
	isGifle = false;
	speed = 90;
	sf::RectangleShape* rect = new sf::RectangleShape(sf::Vector2f(100, 200));
	//rect->setOrigin(rect->getSize().x / 2, 0);
	rect->setFillColor(sf::Color::Blue);
	rect->setOutlineColor(sf::Color::Green);
	rect->setOutlineThickness(4);
	setSprite(rect);
	size = sf::Vector2f(100, 300);

}

Etudiant::~Etudiant() {

}

void Etudiant::update() {
	pos.x += dir * speed * (*deltaTime);

}

void Etudiant::actionOnClick() {
	if (isGifle) return;
	isGifle = true;
	speed *= 5;
	std::cout << "comment osez vous" << std::endl;

	//change de sprite;
}

NonMasque::NonMasque(const sf::Vector2f& pos, sf::RenderWindow* w, float _dir, float* _deltaTime) : Etudiant(pos, w, _dir, _deltaTime){

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