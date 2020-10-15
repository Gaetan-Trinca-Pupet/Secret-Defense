#include <SFML/Graphics.hpp>

#include "header/miniJeu/MiniJeu.h"
#include "header/testMiniJeu.h"
#include "header/miniJeu/EteindrePC/EteindrePC.h"

int main(){
	AppData app;
	app.window.create(sf::VideoMode(960, 540), "test");
	app.window.setFramerateLimit(60);
	//UnMiniJeu unMiniJeu(app);
	//unMiniJeu.play();
	app.difficulty = 10;
	MiniJeu * jeu = new EteindrePC::EteindrePC(app);
	jeu->play();
	delete jeu;
	return 0;
}