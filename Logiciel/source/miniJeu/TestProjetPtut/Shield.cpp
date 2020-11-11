#include "../../../header/miniJeu/TestProjetPtut/Shield.h"

TestProjetPtut::Shield::Shield(){
	texture.loadFromFile("../ressource/TestProjetPtut/shild.bmp");
	sprite.setTexture(texture);
	sprite.setScale(0.9,0.9);
	sprite.setOrigin(texture.getSize().x/2,0);
	pv = 10;
	active = true;
}

void TestProjetPtut::Shield::update(){
	sprite.setPosition(sf::Vector2f(position->x,position->y-40));
	if(pv <= 0 && cooldown.getElapsedTime().asSeconds()>5)pv=10;
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