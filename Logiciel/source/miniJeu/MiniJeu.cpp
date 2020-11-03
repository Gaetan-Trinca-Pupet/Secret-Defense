#include "../../header/miniJeu/MiniJeu.h"

MiniJeu::MiniJeu(AppData& appData) : app(appData), isFinished(false), backgroundColor(sf::Color(0,0,0,255)){
	
}

void MiniJeu::play() {

	this->setup();
	while (app.window.isOpen() && !isFinished) {

		deltaTime = deltaTimeClock.restart().asSeconds();

		app.window.clear(backgroundColor);
		this->update();
		this->draw();
		app.window.display();

		sf::Event event;
		while (app.window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				app.window.close();
				return;
			}
		}

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