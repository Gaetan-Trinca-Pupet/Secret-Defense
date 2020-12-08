#include "../header/testMiniJeu.h"

UnMiniJeu::UnMiniJeu(AppData& appData) : MiniJeu(appData){
	
}

void UnMiniJeu::setup(){
	direction = sf::Vector2f(3,3);
	app.window.setFramerateLimit(60);
	setBackgroundColor(sf::Color(255,255,255));
	rectangle.setPosition(app.window.getSize().x/2,app.window.getSize().y/2);
	rectangle.setSize(sf::Vector2f(18,18));
	rectangle.setFillColor(sf::Color(255,0,0));

    //tempsMax = 8;
	chrono = Chrono(app.window);

}

void UnMiniJeu::draw(){
	app.window.draw(rectangle);
	app.window.draw(chrono);
}

void UnMiniJeu::update(){
	if(rectangle.getPosition().x < 0)direction.x = 3;
	else if(rectangle.getPosition().x > app.window.getSize().x)direction.x = -3;
	if(rectangle.getPosition().y < 0)direction.y = 3;
	else if(rectangle.getPosition().y > app.window.getSize().y)direction.y = -3;
	rectangle.move(direction);
	chrono.update();
	
}
