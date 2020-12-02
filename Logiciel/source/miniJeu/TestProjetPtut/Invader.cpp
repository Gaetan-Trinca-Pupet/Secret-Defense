#include "../../../header/miniJeu/TestProjetPtut/Invader.h"

TestProjetPtut::Invader::Invader(sf::Vector2f pos){
	sprite.setPosition(pos);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::Rect<int>(0,0,32,32));
	sprite.setOrigin(sf::Vector2f(16,16));
	signe_speed = 1;
	if(std::rand()%2==0)signe_speed = -1;
	speed = sf::Vector2f(signe_speed*(2*3.14159265)/220,0.6);
	x_sin = 0;
	pv = 3;
	invulnerability = false;
	cooldown.restart();
}

void TestProjetPtut::Invader::update(){
	if(invulnerability){
		if(invulnerabilityDuration.getElapsedTime().asSeconds() > 0.3){
			invulnerability = false;
			sprite.setTextureRect(sf::Rect<int>(0,0,32,32));
		}
		if(isKilled() && invulnerabilityDuration.getElapsedTime().asSeconds() > 0.2){
			sprite.setTextureRect(sf::Rect<int>(32,32,32,32));
		}else if(isKilled() && invulnerabilityDuration.getElapsedTime().asSeconds() > 0.1){
			sprite.setTextureRect(sf::Rect<int>(32,0,32,32));
		}
		return;
	}else{
		if(sprite.getPosition().y > 420){
			sprite.move(0,5);
		}else{
			speed.x += signe_speed*(2*3.14159265)/220;
			x_sin = std::sin(speed.x)*240;
			sprite.setPosition(x_sin+480, sprite.getPosition().y+speed.y);
		}
		
		if(cooldown.getElapsedTime().asSeconds() >= 0.8 && sprite.getPosition().y <= 410 && sprite.getPosition().y >= 0){
			balls->push_back(Ball(sprite.getPosition()));
			cooldown.restart();
		}
		
		for(Missile& missile : *missiles){
			if( missile.getPosition().x < sprite.getPosition().x + sprite.getTextureRect().width/2 + 2
			  && missile.getPosition().x + sprite.getTextureRect().width/2 + 2 > sprite.getPosition().x
			  && missile.getPosition().y < sprite.getPosition().y + sprite.getTextureRect().height/2 +2
			  && missile.getPosition().y + sprite.getTextureRect().height/2 + 2 > sprite.getPosition().y){
				missile.kill();
				inflictDamage(1);
			}
		}
	
	}
	
	for(Ball& ball : *balls){
		if(!ball.isEnemy() &&
			 (ball.getPosition().x-sprite.getPosition().x)*(ball.getPosition().x-sprite.getPosition().x)
		   + (ball.getPosition().y-sprite.getPosition().y)*(ball.getPosition().y-sprite.getPosition().y)
		   < (sprite.getTextureRect().width/2+8)*(sprite.getTextureRect().height/2+8)){
			   if(pv > 0)inflictDamage(pv);
		   }
	}
	
	
}

void TestProjetPtut::Invader::draw(sf::RenderWindow& window){
	window.draw(sprite);
}

bool TestProjetPtut::Invader::mustBeDestroyed()const{
	return !invulnerability && isKilled() || sprite.getPosition().y > 580;
}

bool TestProjetPtut::Invader::isKilled()const{
	return pv <= 0;
}

void TestProjetPtut::Invader::inflictDamage(const short int damage){
	pv -= damage;
	if(pv > 0)sprite.setTextureRect(sf::Rect<int>(0,32,32,32));
	invulnerability = true;
	invulnerabilityDuration.restart();
}

sf::Texture TestProjetPtut::Invader::texture;
std::vector<TestProjetPtut::Ball>* TestProjetPtut::Invader::balls;
std::vector<TestProjetPtut::Missile>* TestProjetPtut::Invader::missiles;