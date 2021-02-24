#include "../../../header/miniJeu/EteindrePC/Personnage.h"

//test

EteindrePC::Personnage::Personnage(){
	direction = EteindrePC::Direction::Bas;
	texture.loadFromFile("../ressource/EteindrePC/monsieurLAPORTE.png");
	sprite.setTexture(texture);
	controles.setUpKey(sf::Keyboard::Key::Up);
	controles.setUpKey(sf::Keyboard::Key::Z);
	controles.setDownKey(sf::Keyboard::Key::Down);
	controles.setDownKey(sf::Keyboard::Key::S);
	controles.setLeftKey(sf::Keyboard::Key::Left);
	controles.setLeftKey(sf::Keyboard::Key::Q);
	controles.setRightKey(sf::Keyboard::Key::Right);
	controles.setRightKey(sf::Keyboard::Key::D);
	controles.setActionKey(sf::Keyboard::Key::Space);
}

void EteindrePC::Personnage::draw(sf::RenderWindow& window){
	sprite.setPosition(position);
	sprite.setTextureRect(sf::IntRect(64*sprite_x,Personnage::direction*64,64,64));
	window.draw(sprite);
}

void EteindrePC::Personnage::update(){
	controles.update();
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
	
	if(controles.isUpPressed() && !controles.isDownPressed()){
		direction = EteindrePC::Direction::Haut;
		bool canPass(true);
		if(position.y -6 < -up_offset)canPass= false;
		for(CollisionBox* box : collisionList){
			if(position.y > box->getPosition().y && position.y - 6 + up_offset < box->getPosition().y + box->getSize().y
					&& position.x + right_offset > box->getPosition().x && position.x + left_offset < box->getPosition().x + box->getSize().x){
				canPass = false;
				break;
			}
		}
		if(canPass)position.y -= 6;
		hasMoved = true;
	}else if(controles.isDownPressed() && !controles.isUpPressed()){
		direction = EteindrePC::Direction::Bas;
		bool canPass(true);
		if(position.y + 6 > 540-down_offset)canPass= false;
		for(CollisionBox* box : collisionList){
			if(position.y + down_offset < box->getPosition().y + box->getSize().y && position.y + 6 + down_offset > box->getPosition().y 
					&& position.x + right_offset > box->getPosition().x && position.x + left_offset < box->getPosition().x + box->getSize().x){
				canPass = false;
				break;
			}
		}
		if(canPass)position.y += 6;
		hasMoved = true;
	}else if(controles.isLeftPressed() && !controles.isRightPressed()){
		direction = EteindrePC::Direction::Gauche;
		bool canPass(true);
		if(position.x - 6 < -left_offset)canPass= false;
		for(CollisionBox* box : collisionList){
			if(position.x + right_offset > box->getPosition().x + box->getSize().x && position.x + left_offset - 6 < box->getPosition().x + box->getSize().x
					&& position.y + down_offset  > box->getPosition().y && position.y + up_offset < box->getPosition().y + box->getSize().y){
				canPass = false;
				break;
			}
		}
		if(canPass)position.x -= 6;
		hasMoved = true;
	}else if(controles.isRightPressed() && !controles.isLeftPressed()){
		direction = EteindrePC::Direction::Droite;
		bool canPass(true);
		if(position.x + 6 > 960-right_offset)canPass= false;
		for(CollisionBox* box : collisionList){
			if(position.x + left_offset  < box->getPosition().x + box->getSize().x && position.x + right_offset + 6 > box->getPosition().x 
					&& position.y + down_offset  > box->getPosition().y && position.y + up_offset < box->getPosition().y + box->getSize().y){
				canPass = false;
				break;
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

std::pair<sf::Vector2f*,EteindrePC::Direction*> EteindrePC::Personnage::getPersoView(){
	return std::pair<sf::Vector2f*,Direction*>(&position,&direction);
}
