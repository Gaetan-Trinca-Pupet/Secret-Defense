#include "../../../header/miniJeu/TestProjetPtut/Invader.h"

TestProjetPtut::Invader::Invader(sf::Vector2f pos){
	sprite.setPosition(pos);
	sprite.setTexture(texture);
	sprite.setOrigin(sf::Vector2f(texture.getSize().x/2,texture.getSize().y/2));
	int signe_speed = 1;
	if(std::rand()%2==0)signe_speed = -1;
	speed = sf::Vector2f(signe_speed*(2*3.14159265)/220,0.6);
	x_sin = 0;
	pv = 3;
	cooldown.restart();
}

void TestProjetPtut::Invader::update(){
	if(sprite.getPosition().y > 420){
		sprite.move(0,5);
	}else{
		speed.x += (2*3.14159265)/220;
		x_sin = std::sin(speed.x)*240;
		sprite.setPosition(x_sin+480, sprite.getPosition().y+speed.y);
	}
	
	if(cooldown.getElapsedTime().asSeconds() >= 0.8 && sprite.getPosition().y <= 410 && sprite.getPosition().y >= 0){
		balls->push_back(Ball(sprite.getPosition()));
		cooldown.restart();
	}
	
	for(Ball& ball : *balls){
		if(!ball.isEnemy() &&
			 (ball.getPosition().x-sprite.getPosition().x)*(ball.getPosition().x-sprite.getPosition().x)
		   + (ball.getPosition().y-sprite.getPosition().y)*(ball.getPosition().y-sprite.getPosition().y)
		   < (texture.getSize().x/2+8)*(texture.getSize().y/2+8)){
			   pv=0;
		   }
	}
}

void TestProjetPtut::Invader::draw(sf::RenderWindow& window){
	window.draw(sprite);
}

bool TestProjetPtut::Invader::mustBeDestroyed()const{
	return isKilled() || sprite.getPosition().y > 580;
}

bool TestProjetPtut::Invader::isKilled()const{
	return pv <= 0;
}

sf::Texture TestProjetPtut::Invader::texture;
std::vector<TestProjetPtut::Ball>* TestProjetPtut::Invader::balls;