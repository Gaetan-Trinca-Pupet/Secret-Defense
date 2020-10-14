#include <SFML/Graphics.hpp>

#include "header/miniJeu/MiniJeu.h"
#include "header/testMiniJeu.h"
#include "header/clickable.h"

int main(){
    AppData app;
    app.window.create(sf::VideoMode(960, 540), "test");
    app.window.setFramerateLimit(60);


    while(app.window.isOpen()){
        sf::Event event;
        while(app.window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                app.window.close();
                return 0;
            }
        }
        app.window.clear();
        test->onClick();
        app.window.draw(*test);
        app.window.display();
    }
    delete test;
    return 0;
}
