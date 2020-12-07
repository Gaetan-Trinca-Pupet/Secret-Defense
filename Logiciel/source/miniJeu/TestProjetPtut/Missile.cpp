#include "../../../header/miniJeu/TestProjetPtut/Missile.h"

TestProjetPtut::Missile::Missile(const sf::Vector2f& position){
	rectangleShape.setPosition(position);
	rectangleShape.setOrigin(sf::Vector2f(1,10));
	rectangleShape.setSize(sf::Vector2f(2,20));
	rectangleShape.setOutlineThickness(3);
	rectangleShape.setOutlineColor(sf::Color(100,220,255));
	rectangleShape.setFillColor(sf::Color(220,240,255));
	isKilled = false;
}

void TestProjetPtut::Missile::update(){
	rectangleShape.move(0,speed());
}

void TestProjetPtut::Missile::draw(sf::RenderWindow& window){
	window.draw(rectangleShape);
}

void TestProjetPtut::Missile::kill(){
	isKilled = true;
}

bool TestProjetPtut::Missile::mustBeDestroyed()const{
	return rectangleShape.getPosition().y < -50 || isKilled;
}

const sf::Vector2f& TestProjetPtut::Missile::getPosition()const{
	return rectangleShape.getPosition();
}