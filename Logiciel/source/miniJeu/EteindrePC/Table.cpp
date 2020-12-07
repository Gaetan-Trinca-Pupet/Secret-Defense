#include "../../../header/miniJeu/EteindrePC/Table.h"

EteindrePC::Table::Table(const sf::Vector2f& pos_, const sf::Vector2f& size_): body(pos_, size_){
	
}

void EteindrePC::Table::draw(sf::RenderWindow& window){
	sf::RectangleShape rectangle(body.getSize());
	rectangle.setPosition(body.getPosition());
	rectangle.setFillColor(sf::Color(200,200,200));
	window.draw(rectangle);
}

EteindrePC::CollisionBox& EteindrePC::Table::getCollisionBox(){
	return body;
}