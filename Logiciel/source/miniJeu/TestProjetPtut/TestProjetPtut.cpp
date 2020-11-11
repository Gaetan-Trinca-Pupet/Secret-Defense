#include "../../../header/miniJeu/TestProjetPtut/TestProjetPtut.h"

TestProjetPtut::TestProjetPtut::TestProjetPtut(AppData& appData): MiniJeu(appData){
	Invader::texture.loadFromFile("../ressource/TestProjetPtut/Invader.bmp");
	Ball::texture.loadFromFile("../ressource/TestProjetPtut/balle.bmp");
	Invader::balls = &balls;
}

void TestProjetPtut::TestProjetPtut::setup(){
	std::srand(std::time(NULL));
	setBackgroundColor(sf::Color(0,0,0));
	ccc =4;
	textureBackground.loadFromFile("../ressource/TestProjetPtut/bg.bmp");
	textureBackground.setRepeated(true);
	background.setTexture(textureBackground);
	background.setTextureRect(sf::IntRect(0,0,540,540));
	background.setPosition(sf::Vector2f((960-540)/2,0));
	spaceship.bindControles(controles);
	spaceship.setPositionLimit(sf::Vector2f(background.getTextureRect().left+background.getPosition().x,background.getTextureRect().width+background.getPosition().x));
	spaceship.setBalls(&balls);
	h_ccc = std::rand()%100;
	appInv.restart();
	font.loadFromFile("../ressource/fonts/OpenSans-Regular.ttf");
	textfield.setPosition(sf::Vector2f(200,200));
	textfield.setSize(sf::Vector2u(500,50));
	textfield.setFont(font);
	textfield.setMaxLength(20);
	textfield.setFillColor(sf::Color(127,127,127));
	textfield.setTextColor(sf::Color(0,0,0));
}

void TestProjetPtut::TestProjetPtut::draw(){
	app.window.draw(background);
	spaceship.draw(app.window);
	for(Ball& ball : balls){
		ball.draw(app.window);
	}
	
	for(Invader& invader : invaders){
		invader.draw(app.window);
	}
	textfield.draw(app.window);
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
			invaders.erase(invaders.begin()+i);
		}
	}
	
	if(ccc > 0 && appInv.getElapsedTime().asSeconds()>0.5){
		invaders.push_back(Invader(sf::Vector2f(960/2,-h_ccc)));
		--ccc;
		appInv.restart();
	}else if(ccc == 0 && appInv.getElapsedTime().asSeconds()>6.5){
		ccc=4;
		h_ccc = std::rand()%100;
	}
	textfield.update(app.window);
}