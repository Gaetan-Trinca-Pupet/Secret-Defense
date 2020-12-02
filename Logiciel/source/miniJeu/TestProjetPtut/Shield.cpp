#include "../../../header/miniJeu/TestProjetPtut/Shield.h"

TestProjetPtut::Shield::Shield(){
	texture.loadFromFile("../ressource/TestProjetPtut/bouclier.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::Rect<int>(0,0,80,11));
	sprite.setScale(0.9,0.9); //11*80
	sprite.setOrigin(sprite.getLocalBounds().width/2,0);
	pv = 10;
	active = true;
}

void TestProjetPtut::Shield::update(){
	sprite.setPosition(sf::Vector2f(position->x,position->y-40));
	if(pv <= 0 && cooldown.getElapsedTime().asSeconds()>5){
		pv=10;
		active = true;
	}
	for(Ball& ball : *balls){
		if(active && ball.isEnemy() && sprite.getPosition().x + 50 > ball.getPosition().x-8 && sprite.getPosition().x - 50 < ball.getPosition().x+8 && 
		sprite.getPosition().y+5 > ball.getPosition().y -8 && sprite.getPosition().y-5 < ball.getPosition().y +8){
			ball.changeDirection();
			if(damageCooldown.getElapsedTime().asSeconds() >= 0.5){
				pv -= 1;
				damageCooldown.restart();
				if(pv <= 0){
					active = false;
					cooldown.restart();
				}
			}
		}
	}
	if(animationClock.getElapsedTime().asMilliseconds()>200)animationClock.restart();
	sprite.setTextureRect(sf::Rect<int>((5-pv/2)*80,11*(animationClock.getElapsedTime().asMilliseconds()/50),80,11));
}

void TestProjetPtut::Shield::draw(sf::RenderWindow& window){
	if(active)window.draw(sprite);
}

void TestProjetPtut::Shield::bindPosition(const sf::Vector2f& pos){
	position = &pos;
}

void TestProjetPtut::Shield::turnOnOff(){
	if(pv > 0)active = (!active)&1;
}

void TestProjetPtut::Shield::setBalls(std::vector<Ball> * tabBall){
	balls = tabBall;
}

bool TestProjetPtut::Shield::isActive()const{
	return active;
}