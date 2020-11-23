#include "../../../header/miniJeu/Gifle/Gifle.h"
#include <iostream>



Passant::Passant(const sf::Vector2f& pos, sf::RenderWindow* w, float _dir, float* _deltaTime)
	:Clickable(pos, sf::Vector2f(), w)
{
	window = w;
	deltaTime = _deltaTime;
	dir = _dir;
	isGifle = false;
	speed = 110;
	speed += (float(rand()) / float(RAND_MAX) - 0.5) * float(speed * 0.3);
	
	sf::RectangleShape* rect = new sf::RectangleShape(sf::Vector2f(175, 500));
	setFillColor(sf::Color::Blue);
	setOutlineColor(sf::Color::Green);
	setOutlineThickness(4);
	setSize(sf::Vector2f(175, 85));

	

}

Passant::~Passant() {
}

void Passant::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	sf::RectangleShape rect(*this);
	rect.setSize(sf::Vector2f(getSize().x, 300));
	target.draw(rect);
}

void Passant::update() {

	move(dir * speed * (*deltaTime), 0);
}

bool Passant::isOutOfBounds()
{
	return (dir > 0)  && getPosition().x >   window->getSize().x + getOutlineThickness()
		|| (dir <= 0) && getPosition().x < - getOutlineThickness() - getSize().x;
}

void Passant::actionOnClick() {
	if (isGifle) return;
	isGifle = true;
	speed *= 8;
	std::cout << "comment osez vous" << std::endl;

	//change de sprite;
}

NonMasque::NonMasque(const sf::Vector2f& pos, sf::RenderWindow* w, float _dir, float* _deltaTime) : Passant(pos, w, _dir, _deltaTime){

	setOutlineColor(sf::Color::Red);
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

bool Passant::operator < (Passant& p2) {
	return getPosition().y < p2.getPosition().y;
}