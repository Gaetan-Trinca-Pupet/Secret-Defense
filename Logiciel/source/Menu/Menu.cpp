#include "../../header/Menu/Menu.h"

Menu::Menu::Menu(AppData& appData) : app(appData){
	//connexion.setFont(app.font);
	menuPrincipal.setFont(app.font);
	menuOptions.setFont(app.font);
	menuGameOver.setFont(app.font);
	menuOptions.setup(app);
	menu = Menus::principal;
	finished = false;
	background.setTexture(AssetManager::getTexture("../ressource/Menu/background_menu.png"));
}

void Menu::Menu::play(){
	finished = false;
	app.window.setFramerateLimit(30);
    while(app.window.isOpen() && !finished){ 
        sf::Event event;
        while(app.window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                app.window.close();
                return;
            }else if(event.type == sf::Event::KeyPressed){
				menuOptions.updateText();
                if(event.key.code == sf::Keyboard::F11){
					
                    if(!app.fullscreen){
                        app.window.create(sf::VideoMode(960, 540), "test",sf::Style::Fullscreen);
                        app.window.setView(sf::View(sf::Vector2f(480,270), sf::Vector2f(960,540)));
						if(app.icon.getPixelsPtr() != nullptr)app.window.setIcon(238,238,app.icon.getPixelsPtr());
                        app.fullscreen = true;
                    }else{
                        app.window.create(sf::VideoMode(960, 540), "test");
						if(app.icon.getPixelsPtr() != nullptr)app.window.setIcon(238,238,app.icon.getPixelsPtr());
                        app.fullscreen = false;
                    }
                }
            }

        }
		app.window.clear(sf::Color(255,255,255));
        this->update();
		app.window.draw(background);
        this->draw();
        app.window.display();
	}
	app.framerateManager.reset();
}

void Menu::Menu::update(){
	//if(menu == Menus::connexion)connexion.update(app.window, menu);
	if(menu == Menus::principal)menuPrincipal.update(app.window, menu);
	else if(menu == Menus::jeu || menu == Menus::quitter)finished=true;
	else if(menu == Menus::options)menuOptions.update(app.window, menu, app);
	else if(menu == Menus::gameOver)menuGameOver.update(app.window, menu);
}

void Menu::Menu::draw(){
	//if(menu == Menus::connexion)connexion.draw(app.window);
	if(menu == Menus::principal)menuPrincipal.draw(app.window);
	else if(menu == Menus::options)menuOptions.draw(app.window);
	else if(menu == Menus::gameOver)menuGameOver.draw(app.window);
}

Menu::Menus Menu::Menu::getMenu()const{
	return menu;
}

void Menu::Menu::setMenu(const Menus m){
	menu = m;
}