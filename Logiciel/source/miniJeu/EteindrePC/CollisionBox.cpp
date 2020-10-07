#include "../../../header/miniJeu/EteindrePC/CollisionBox.h"

EteindrePC::CollisionBox::CollisionBox(const sf::Vector2f& pos, const sf::Vector2f& siz):position(pos),size(siz){
	
}

const sf::Vector2f& EteindrePC::CollisionBox::getPosition()const{
	return position;
}

const sf::Vector2f& EteindrePC::CollisionBox::getSize()const{
	return size;
}

void EteindrePC::CollisionBox::setPosition(const sf::Vector2f& pos){
	position = pos;
}

void EteindrePC::CollisionBox::setSize(const sf::Vector2f& siz){
	size = siz;
}