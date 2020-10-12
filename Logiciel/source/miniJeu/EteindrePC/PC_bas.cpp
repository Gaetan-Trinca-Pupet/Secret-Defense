#include "../../../header/miniJeu/EteindrePC/PC_bas.h"

bool EteindrePC::PC_bas::isPersonnageLookingAt(){
	return position.x <= persoView.first->x + 64 && persoView.first->x + 64 >= position.x && persoView.first->y + 72 >= position.y && persoView.first->y <= position.y + 20 && *persoView.second == EteindrePC::Direction::Bas;
}

void EteindrePC::PC_bas::drawWhenIsOn(sf::RenderWindow& window){
	sf::RectangleShape r(sf::Vector2f(64,64));
	r.setFillColor(sf::Color(255,255,255,255));
	r.setPosition(position);
	window.draw(r);
}

void EteindrePC::PC_bas::drawWhenIsOff(sf::RenderWindow& window){
	sf::RectangleShape r(sf::Vector2f(64,64));
	r.setFillColor(sf::Color(0,0,0,255));
	r.setPosition(position);
	window.draw(r);
}