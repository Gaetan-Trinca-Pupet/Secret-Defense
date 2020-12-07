#include "../../../header/miniJeu/EteindrePC/PC_bas.h"

bool EteindrePC::PC_bas::isPersonnageLookingAt(){
	return position.x <= persoView.first->x + 32 && persoView.first->x <= position.x + 32 && persoView.first->y + 69 >= position.y && persoView.first->y <= position.y +10 && *persoView.second == EteindrePC::Direction::Bas;
}

void EteindrePC::PC_bas::drawWhenIsOn(sf::RenderWindow& window){
	sf::RectangleShape r(sf::Vector2f(56,32));
	r.setFillColor(sf::Color(255,255,255,255));
	r.setPosition(position);
	r.move(4,0);
	window.draw(r);
}

void EteindrePC::PC_bas::drawWhenIsOff(sf::RenderWindow& window){
	sf::RectangleShape r(sf::Vector2f(56,32));
	r.setFillColor(sf::Color(0,0,0,255));
	r.setPosition(position);
	r.move(4,0);
	window.draw(r);
}