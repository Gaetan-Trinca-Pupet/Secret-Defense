#include "../../../header/miniJeu/TestProjetPtut/TestProjetPtut.h"

TestProjetPtut::TestProjetPtut::TestProjetPtut(AppData& appData): MiniJeu(appData),chrono(appData.window){
	app.window.setMouseCursorVisible(false);
	Invader::balls = &balls;
	Invader::missiles = &missiles;
	controles.setLeftKey(sf::Keyboard::Key::Left);
	controles.setLeftKey(sf::Keyboard::Key::Q);
	controles.setRightKey(sf::Keyboard::Key::Right);
	controles.setRightKey(sf::Keyboard::Key::D);
	controles.setActionKey(sf::Keyboard::Key::Space);
	innerInterface.setPv(spaceship.getPv());
}

void TestProjetPtut::TestProjetPtut::setup(){
	chrono.setTempsMax(30);
	setBackgroundColor(sf::Color(0,0,0));
	textureBackground.loadFromFile("../ressource/TestProjetPtut/bg.bmp");
	textureBackground.setRepeated(true);
	background.setTexture(textureBackground);
	background.setTextureRect(sf::IntRect(0,0,540,540));
	background.setPosition(sf::Vector2f((960-540)/2,0));
	spaceship.bindControles(controles);
	Ball::positionLimit = sf::Vector2f(background.getTextureRect().left+background.getPosition().x,background.getTextureRect().width+background.getPosition().x);
	spaceship.setPositionLimit(sf::Vector2f(background.getTextureRect().left+background.getPosition().x,background.getTextureRect().width+background.getPosition().x));
	spaceship.setBalls(&balls);
	spaceship.setMissiles(&missiles);
	spawner.setInvaders(&invaders);
	spawner.setDifficulty(app.difficulty);
}

void TestProjetPtut::TestProjetPtut::draw(){
	app.window.draw(background);
	spaceship.draw(app.window);
	for(Ball& ball : balls){
		ball.draw(app.window);
	}
	
	for(Missile& missile : missiles){
		missile.draw(app.window);
	}
	
	for(Invader& invader : invaders){
		invader.draw(app.window);
	}
	if(glitchEffect.isActive())glitchEffect.draw(app.window);
	innerInterface.draw(app.window);
	app.window.draw(chrono);
}

void TestProjetPtut::TestProjetPtut::update(){
	controles.update();
	spaceship.update();
	
	for(int i(balls.size()-1); i >= 0; --i){
		balls[i].update();
		if(balls[i].mustBeDestroyed())balls.erase(balls.begin()+i);
	}
	
	for(int i(invaders.size()-1); i >= 0; --i){
		invaders[i].update();
		if(invaders[i].mustBeDestroyed()){
			if(!invaders[i].isKilled())spaceship.inflictDamage(2);
			invaders.erase(invaders.begin()+i);
		}
	}
	
	for(int i(missiles.size()-1); i >= 0; --i){
		missiles[i].update();
		if(missiles[i].mustBeDestroyed()){
			missiles.erase(missiles.begin()+i);
		}
	}
	
	spawner.update();
	if(spawner.isWaveFinished()){
		glitchEffect.start(app.window);
		controles.shuffle();
	}
	if(spaceship.getPv() <= 0){
		--app.lives;
		isFinished = true;
		app.window.setMouseCursorVisible(true);
	}else if(chrono.getTimePassed() > 30){
		isFinished = true;
		app.window.setMouseCursorVisible(true);
	}
	glitchEffect.update();
	chrono.update();
}