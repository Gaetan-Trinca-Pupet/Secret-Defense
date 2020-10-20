#include <SFML/Graphics.hpp>

#include "header/miniJeu/MiniJeu.h"
#include "header/testMiniJeu.h"
#include "header/miniJeu/Gifle/Gifle.h"
#include "header/clickable.h"

int main(){
	AppData app;
	app.window.create(sf::VideoMode(960, 540), "test");
	app.window.setFramerateLimit(60);
	//UnMiniJeu unMiniJeu(app);
	//unMiniJeu.play();
	MiniJeu* jeu = new Gifle(app);
	jeu->play();
	delete jeu;
	return 0;
}
