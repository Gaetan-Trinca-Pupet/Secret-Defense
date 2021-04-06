#include "../../../header/miniJeu/EteindrePC/PC_bas.h"

bool EteindrePC::PC_bas::isPersonnageLookingAt(){
	return position.x <= persoView.first->x + 32 && persoView.first->x <= position.x + 32 && persoView.first->y + 69 >= position.y && persoView.first->y <= position.y +10 && *persoView.second == EteindrePC::Direction::Bas;
}

void EteindrePC::PC_bas::drawWhenIsOn(sf::RenderWindow& window){
	sf::Sprite sprite;
	sprite.setTexture(AssetManager::getTexture("../ressource/EteindrePC/PC_bas_ON.png"));
	sprite.setPosition(position);
	window.draw(sprite);
}

void EteindrePC::PC_bas::drawWhenIsOff(sf::RenderWindow& window){
	sf::Sprite sprite;
	sprite.setTexture(AssetManager::getTexture("../ressource/EteindrePC/PC_bas_OFF.png"));
	sprite.setPosition(position);
	window.draw(sprite);
}