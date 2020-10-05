#include <SFML/Graphics.hpp>

#include "header/miniJeu/MiniJeu.h"
#include "header/testMiniJeu.h"

int main(){
	AppData app;
	app.window.create(sf::VideoMode(960, 540), "test");
	app.window.setFramerateLimit(60);
	//UnMiniJeu unMiniJeu(app);
	//unMiniJeu.play();
	MiniJeu * jeu = new UnMiniJeu(app);
	jeu->play();
	delete jeu;
	return 0;
}