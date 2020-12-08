#include "../../header/miniJeu/MiniJeu.h"

MiniJeu::MiniJeu(AppData& appData) : app(appData), isFinished(false), backgroundColor(sf::Color(0,0,0,255)){
	AssetManager::getTexture("../ressource/image/coeur.png").setRepeated(true);
}

void MiniJeu::play(){
	this->setup();
	app.framerateManager.reset();
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
						app.window.setView(sf::View(sf::Vector2f(480,270), sf::Vector2f(960,540)));
						app.fullscreen = true;
					}else{
						app.window.create(sf::VideoMode(960, 540), "test");
						app.fullscreen = false;
					}
					app.framerateManager.reset();
				}
			}
			
		}
		app.window.clear(backgroundColor);
        while(app.framerateManager.mustUpdate())this->update();
		this->draw();
		drawInterface();
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

void MiniJeu::drawInterface(){
    sf::Text texteScore;
    texteScore.setFont(app.font);
    texteScore.setString("Score: "+std::to_string(app.score));
    texteScore.setPosition(app.window.getView().getSize().x-150,app.window.getView().getSize().y-30);
    sf::Sprite sprite;
    sprite.setTexture(AssetManager::getTexture("../ressource/image/coeur.png"));
    sprite.setTextureRect(sf::IntRect(0,0,(23*app.lives),23));
    sprite.setScale(2.0,2.0);
    sprite.setPosition(sf::Vector2f(0,0));
    app.window.draw(sprite);

    app.window.draw(texteScore);
}