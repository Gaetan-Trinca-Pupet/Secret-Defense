#include "../../../header/miniJeu/EteindrePC/Personnage.h"

EteindrePC::Personnage::Personnage(){
	direction = EteindrePC::Direction::Bas;
	texture.loadFromFile("../ressource/EteindrePC/monsieurLAPORTE.png");
	sprite.setTexture(texture);
}

void EteindrePC::Personnage::draw(sf::RenderWindow& window){
	sprite.setPosition(position);
	sprite.setTextureRect(sf::IntRect(64*sprite_x,Personnage::direction*64,64,64));
	window.draw(sprite);
}

void EteindrePC::Personnage::update(){
	bool hasMoved(false);
	if(clock.getElapsedTime() > sf::milliseconds(100)){
		++sprite_x;
		clock.restart();
	}
	sprite_x%=4;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		direction = EteindrePC::Direction::Haut;
		position.y -= 6;
		hasMoved = true;
	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
		direction = EteindrePC::Direction::Bas;
		position.y += 6;
		hasMoved = true;
	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		direction = EteindrePC::Direction::Gauche;
		position.x -= 6;
		hasMoved = true;
	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
		direction = EteindrePC::Direction::Droite;
		position.x += 6;
		hasMoved = true;
	}
	
	if(!hasMoved)sprite_x=0;
}