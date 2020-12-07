#include "../../../header/miniJeu/EteindrePC/Mur.h"

EteindrePC::Mur::Mur(unsigned short int h, unsigned short int l): body(sf::Vector2f(140,h), sf::Vector2f(10,l)){
	
}

void EteindrePC::Mur::draw(sf::RenderWindow& window){
	sf::RectangleShape rectangle(body.getSize());
	rectangle.setPosition(body.getPosition());
	rectangle.setFillColor(sf::Color(0,0,0));
	window.draw(rectangle);
}

EteindrePC::CollisionBox& EteindrePC::Mur::getCollisionBox(){
	return body;
}