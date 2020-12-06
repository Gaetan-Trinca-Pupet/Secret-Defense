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
			}
		}
		app.window.clear(backgroundColor);
        this->update();
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
    if (!coeur.loadFromFile("../ressource/image/coeur.png"))
    {
        std::cout<<"erreur loadFromFile"<<std::endl;
    }
    sf::Text texteScore;
    texteScore.setFont(app.font);
    texteScore.setString("Score: "+std::to_string(app.score));
    texteScore.setPosition(app.window.getView().getSize().x-150,app.window.getView().getSize().y-30);

    coeur.setRepeated(true);
    sf::Sprite sprite;
    sprite.setTexture(coeur);
    sprite.setTextureRect(sf::IntRect(0,0,(23*app.lives),23));
    sprite.setScale(2.0,2.0);
    sprite.setPosition(sf::Vector2f(0,0));
    app.window.draw(sprite);

    app.window.draw(texteScore);
}
