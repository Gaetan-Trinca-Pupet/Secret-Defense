#include "../../header/miniJeu/MiniJeu.h"

MiniJeu::MiniJeu(AppData& appData) : app(appData), isFinished(false), backgroundColor(sf::Color(0,0,0,255)){
	
}

void MiniJeu::play(){
	this->setup();
	while(app.window.isOpen() && !isFinished){
		sf::Event event;
		while(app.window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				app.window.close();
				return;
			}else if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::F11){
					if(!app.fullscreen){
						app.window.create(sf::VideoMode(960, 540), "test",sf::Style::Fullscreen);
						app.window.setView(sf::View(sf::Vector2f(490,270), sf::Vector2f(960,540)));
						app.fullscreen = true;
						app.window.setFramerateLimit(60);
					}else{
						app.window.create(sf::VideoMode(960, 540), "test");
						app.fullscreen = false;
						app.window.setFramerateLimit(60);
					}
				}
			}
			
		}
		app.window.clear(backgroundColor);
		this->update();
		this->draw();
		app.window.display();
	}
}

void MiniJeu::setup(){
	
}

MiniJeu::~MiniJeu(){
	
}

sf::Color MiniJeu::getBackgroundColor()const{
	return backgroundColor;
}

void MiniJeu::setBackgroundColor(const sf::Color& color){
	backgroundColor = color;
}