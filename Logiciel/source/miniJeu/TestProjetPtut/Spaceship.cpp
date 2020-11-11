#include "../../../header/miniJeu/TestProjetPtut/Spaceship.h"

TestProjetPtut::Spaceship::Spaceship(){
	texture.loadFromFile("../ressource/TestProjetPtut/ship.bmp");
	sprite.setTexture(texture);
	sprite.setScale(0.9,0.9);
	sprite.setOrigin(sf::Vector2f(texture.getSize().x/2,texture.getSize().y/2));
	sprite.setPosition(sf::Vector2f(960/2,540-texture.getSize().y/1.5));
	shield.bindPosition(sprite.getPosition());
}

void TestProjetPtut::Spaceship::draw(sf::RenderWindow& window){
	window.draw(sprite);
	shield.draw(window);
}

void TestProjetPtut::Spaceship::update(){
	if(controles->isLeftPressed() &&  !controles->isRightPressed()){
		sprite.move(-12,0);
		if(sprite.getPosition().x < positionLimit.x)sprite.setPosition(sf::Vector2f(positionLimit.x, sprite.getPosition().y));
	}else if(controles->isRightPressed() && !controles->isLeftPressed()){
		sprite.move(12,0);
		if(sprite.getPosition().x > positionLimit.y)sprite.setPosition(sf::Vector2f(positionLimit.y, sprite.getPosition().y));
	}
	shield.update();
	if(controles->isActionClicked())shield.turnOnOff();
}

void TestProjetPtut::Spaceship::bindControles(Controles& contr){
	controles = &contr;
}

void TestProjetPtut::Spaceship::setPositionLimit(const sf::Vector2f& pl){
	positionLimit = pl;
}

void TestProjetPtut::Spaceship::setBalls(std::vector<Ball> * tabBall){
	balls = tabBall;
	shield.setBalls(balls);
}