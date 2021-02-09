#include "../../header/Menu/Menu.h"

Menu::Menu::Menu(AppData& appData) : app(appData){
	connexion.setFont(app.font);
}

void Menu::Menu::play(){
	app.window.setFramerateLimit(30);
    while(app.window.isOpen()){ 
        sf::Event event;
        while(app.window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                app.window.close();
                return;
            }else if(event.type == sf::Event::KeyPressed){
				connexion.updateText();
                if(event.key.code == sf::Keyboard::F11){
					
                    if(!app.fullscreen){
                        app.window.create(sf::VideoMode(960, 540), "test",sf::Style::Fullscreen);
                        app.window.setView(sf::View(sf::Vector2f(480,270), sf::Vector2f(960,540)));
                        app.fullscreen = true;
                    }else{
                        app.window.create(sf::VideoMode(960, 540), "test");
                        app.fullscreen = false;
                    }
                }
            }

        }
		app.window.clear(sf::Color(255,255,255));
        this->update();
        this->draw();
        app.window.display();
	}
	app.framerateManager.reset();
}

void Menu::Menu::update(){
	connexion.update(app.window);
}

void Menu::Menu::draw(){
	connexion.draw(app.window);
}