#include "../../../header/miniJeu/EteindrePC/PC_haut.h"

bool EteindrePC::PC_haut::isPersonnageLookingAt(){
	return position.x <= persoView.first->x + 32 && persoView.first->x <= position.x + 32 
	&& persoView.first->y + 32 >= position.y && persoView.first->y - 5 <= position.y + 32
	&& *persoView.second == EteindrePC::Direction::Haut;
}

void EteindrePC::PC_haut::drawWhenIsOn(sf::RenderWindow& window){
	sf::Sprite sprite;
	sprite.setTexture(AssetManager::getTexture("../ressource/EteindrePC/PC_haut_ON.png"));
	sprite.setPosition(position);
	window.draw(sprite);
}

void EteindrePC::PC_haut::drawWhenIsOff(sf::RenderWindow& window){
	sf::Sprite sprite;
	sprite.setTexture(AssetManager::getTexture("../ressource/EteindrePC/PC_haut_OFF.png"));
	sprite.setPosition(position);
	window.draw(sprite);
}