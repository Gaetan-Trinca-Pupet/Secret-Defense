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
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		direction = EteindrePC::Direction::Haut;
		position.y -= 4;
	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
		direction = EteindrePC::Direction::Bas;
		position.y += 4;
	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		direction = EteindrePC::Direction::Gauche;
		position.x -= 4;
	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
		direction = EteindrePC::Direction::Droite;
		position.x += 4;
	}
}