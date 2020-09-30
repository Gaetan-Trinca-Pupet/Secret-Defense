#include <SFML/Graphics.hpp>

#include "header/MiniJeu.h"
#include "header/testMiniJeu.h"

int main(){
	AppData app;
	app.window.create(sf::VideoMode(800, 600), "test");
	UnMiniJeu unMiniJeu(app);
	unMiniJeu.play();
	return 0;
}