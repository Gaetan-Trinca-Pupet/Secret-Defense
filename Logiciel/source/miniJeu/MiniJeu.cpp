#include "../../header/miniJeu/MiniJeu.h"

MiniJeu::MiniJeu(AppData& appData) : app(appData), isFinished(false), backgroundColor(sf::Color(0,0,0,255)){
	AssetManager::getTexture("../ressource/image/coeur.png").setRepeated(true);
}

std::string MiniJeu::play(){

    isFinished=false;
    over = false;
	this->setup();
	app.framerateManager.reset();
    while(app.window.isOpen() && !over){
        sf::Event event;
        while(app.window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                app.window.close();
                return "";
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
        while (app.framerateManager.mustUpdate())
        {
            if (!isFinished) this->update();
            else this->updateOnEnd();
        }
        this->draw();
        drawInterface();
        app.window.display();
    }
    return endMsg;
}

void MiniJeu::setup(){
	
}

void MiniJeu::end(bool won, std::string message)
{
    if (isFinished) return;
    endMsg = message;
    app.mainMusique.stop();
    AssetManager::playSound("../ressource/audio/" + std::string(won ? "success" : "defeat") + ".wav");
    endDelay.restart();
    isFinished = true;
    if (!won) app.lives -= 1;
}

MiniJeu::~MiniJeu(){
	
}

sf::Color MiniJeu::getBackgroundColor()const{
	return backgroundColor;
}

void MiniJeu::setBackgroundColor(const sf::Color& color){
	backgroundColor = color;
}

void MiniJeu::updateOnEnd()
{
    if (endDelay.getElapsedTime().asSeconds() > 1.5)
    {
        over = true;
        return;
    }
    update();
}

void MiniJeu::drawInterface(){
    sf::Text texteScore;
    texteScore.setFont(app.font);
    texteScore.setString("Score: "+std::to_string(app.score));
    texteScore.setPosition(app.window.getView().getSize().x-155,app.window.getView().getSize().y-35);
    texteScore.setOutlineColor(sf::Color::Black);
    texteScore.setOutlineThickness(2);
    sf::Sprite spriteCoeur;
    spriteCoeur.setTexture(AssetManager::getTexture("../ressource/image/coeur.png"));
    spriteCoeur.setTextureRect(sf::IntRect(0,0,(23*app.lives),23));
    spriteCoeur.setScale(2.0,2.0);
    spriteCoeur.setPosition(sf::Vector2f(5,5));
    app.window.draw(spriteCoeur);
    app.window.draw(texteScore);
}
