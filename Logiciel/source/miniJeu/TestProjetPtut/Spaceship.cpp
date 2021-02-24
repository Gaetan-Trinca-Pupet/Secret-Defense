#include "../../../header/miniJeu/TestProjetPtut/Spaceship.h"

TestProjetPtut::Spaceship::Spaceship(){
	texture.loadFromFile("../ressource/TestProjetPtut/ship.bmp");
	sprite.setTexture(texture);
	sprite.setScale(0.9,0.9);
	sprite.setOrigin(sf::Vector2f(texture.getSize().x/2,texture.getSize().y/2));
	sprite.setPosition(sf::Vector2f(960/2,540-texture.getSize().y/1.5));
	shield.bindPosition(sprite.getPosition());
	pv = 8;
	cooldown.restart();
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
	if(controles->isActionPressed() && shield.isActive())shield.turnOnOff();
	else if(!controles->isActionPressed()  && !shield.isActive())shield.turnOnOff();
	if(!shield.isActive() && cooldown.getElapsedTime().asSeconds() > cooldown_duration()){
		cooldown.restart();
		missiles->push_back(sprite.getPosition());
	}
	for(Ball& ball : *balls){
		if(   	sprite.getGlobalBounds().left < ball.getGlobalBounds().left + ball.getGlobalBounds().width
			&&	sprite.getGlobalBounds().left + sprite.getGlobalBounds().width > ball.getGlobalBounds().left
			&&	sprite.getGlobalBounds().top < ball.getGlobalBounds().top + ball.getGlobalBounds().height
			&&	sprite.getGlobalBounds().top + sprite.getGlobalBounds().height > ball.getGlobalBounds().top){
			ball.kill();
			inflictDamage(1);
		}
	}
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

void TestProjetPtut::Spaceship::setMissiles(std::vector<Missile> * tabMissile){
	missiles = tabMissile;
}

void TestProjetPtut::Spaceship::inflictDamage(const short int damage){
	pv -= damage;
	if(pv < 0) pv = 0;
}

const short int& TestProjetPtut::Spaceship::getPv()const{
	return pv;
}