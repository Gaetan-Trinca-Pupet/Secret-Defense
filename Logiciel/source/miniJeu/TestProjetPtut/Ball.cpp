#include "../../../header/miniJeu/TestProjetPtut/Ball.h"

TestProjetPtut::Ball::Ball(const sf::Vector2f& position, const sf::Vector2f& dir){
	sprite.setPosition(position);
	sprite.setTexture(texture);
	sprite.setOrigin(sf::Vector2f(texture.getSize().x/2,texture.getSize().y/2));
	direction = dir;
	enemy = true;
	killed = false;
}

void TestProjetPtut::Ball::update(){
	sprite.move(direction);
}

void TestProjetPtut::Ball::draw(sf::RenderWindow& window){
	window.draw(sprite);
}

void TestProjetPtut::Ball::changeDirection(){
	direction.y *= -1;
	enemy = false;
}

const sf::Vector2f& TestProjetPtut::Ball::getPosition()const{
	return sprite.getPosition();
}

bool TestProjetPtut::Ball::isEnemy()const{
	return enemy;
}

bool TestProjetPtut::Ball::mustBeDestroyed()const{
	return killed || sprite.getPosition().y < - 20 || sprite.getPosition().y > 560;
}

void TestProjetPtut::Ball::kill(){
	killed = true;
}

sf::Texture TestProjetPtut::Ball::texture;