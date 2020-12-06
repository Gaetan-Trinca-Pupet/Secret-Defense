#include "../../../header/miniJeu/TestProjetPtut/Ball.h"

TestProjetPtut::Ball::Ball(const sf::Vector2f& position, const sf::Vector2f& dir){
	sprite.setPosition(position);
	sprite.setTexture(AssetManager::getTexture("../ressource/TestProjetPtut/balle.bmp"));
	sprite.setOrigin(sf::Vector2f(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2));
	direction = dir;
	enemy = true;
	killed = false;
	if(direction.y <= 0){
		direction = sf::Vector2f((std::rand()%100-50)/float(5),(std::rand()%70+30)/float(10));
	}
}

void TestProjetPtut::Ball::update(){
	if(sprite.getPosition().x < positionLimit.x + sprite.getGlobalBounds().width || sprite.getPosition().x + sprite.getGlobalBounds().width > positionLimit.y)direction.x *= -1;
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

const sf::Rect<float> TestProjetPtut::Ball::getGlobalBounds()const{
	return sprite.getGlobalBounds();
}

sf::Vector2f TestProjetPtut::Ball::positionLimit;