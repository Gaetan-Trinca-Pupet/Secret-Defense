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
	
	constexpr int left_offset = 16;
	constexpr int right_offset = 64-16;
	constexpr int up_offset = 64-20;
	constexpr int down_offset = 60;
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		direction = EteindrePC::Direction::Haut;
		bool canPass(true);
		for(CollisionBox* box : collisionList){
			if(position.y > box->getPosition().y && position.y - 6 + up_offset < box->getPosition().y + box->getSize().y
					&& position.x + right_offset > box->getPosition().x && position.x + left_offset < box->getPosition().x + box->getSize().x){
				canPass = false;
			}
		}
		if(canPass)position.y -= 6;
		hasMoved = true;
	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
		direction = EteindrePC::Direction::Bas;
		bool canPass(true);
		for(CollisionBox* box : collisionList){
			if(position.y + down_offset < box->getPosition().y + box->getSize().y && position.y + 6 + down_offset > box->getPosition().y 
					&& position.x + right_offset > box->getPosition().x && position.x + left_offset < box->getPosition().x + box->getSize().x){
				canPass = false;
			}
		}
		if(canPass)position.y += 6;
		hasMoved = true;
	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		direction = EteindrePC::Direction::Gauche;
		bool canPass(true);
		for(CollisionBox* box : collisionList){
			if(position.x + right_offset > box->getPosition().x + box->getSize().x && position.x + left_offset - 6 < box->getPosition().x + box->getSize().x
					&& position.y + down_offset  > box->getPosition().y && position.y + up_offset < box->getPosition().y + box->getSize().y){
				canPass = false;
			}
		}
		if(canPass)position.x -= 6;
		hasMoved = true;
	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
		direction = EteindrePC::Direction::Droite;
		bool canPass(true);
		for(CollisionBox* box : collisionList){
			if(position.x + left_offset  < box->getPosition().x + box->getSize().x && position.x + right_offset + 6 > box->getPosition().x 
					&& position.y + down_offset  > box->getPosition().y && position.y + up_offset < box->getPosition().y + box->getSize().y){
				canPass = false;
			}
		}
		if(canPass)position.x += 6;
		hasMoved = true;
	}
	
	if(!hasMoved)sprite_x=0;
}

void EteindrePC::Personnage::addCollisionBox(CollisionBox& collisionBox){
	collisionList.push_back(&collisionBox);
}