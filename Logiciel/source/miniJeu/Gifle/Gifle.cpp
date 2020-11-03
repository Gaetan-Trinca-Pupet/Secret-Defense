#include "../../../header/miniJeu/Gifle/Gifle.h"
#include <iostream>
#include <time.h>

bool compareEtudiantPtr(Etudiant* e1, Etudiant* e2)
{
	return (*e1 < *e2);
}

Gifle::Gifle(AppData& appData) : MiniJeu(appData) {
	isFinished = false;
	time = 20;
	chrono = Chrono(time, &clock, app.window);
	mouseIsAlreadyPressed = false;
	wave = 0;
	srand(std::time(NULL));
}

Gifle::~Gifle() {

}

void Gifle::setup() {

	/*etudiants.push_back(new Etudiant(sf::Vector2f(0, 180), &app.window, 1, &deltaTime));
	etudiants.push_back(new Etudiant(sf::Vector2f(-200, app.window.getSize().y-250), &app.window, 1, &deltaTime));
	etudiants.push_back(new Etudiant(sf::Vector2f(app.window.getSize().x+10, 150), &app.window, -1, &deltaTime));
	etudiants.push_back(new NonMasque(sf::Vector2f(app.window.getSize().x+350, 210), &app.window, -1, &deltaTime));
	etudiants.push_back(new NonMasque(sf::Vector2f(-60, 100), &app.window, 1, &deltaTime));*/
	

}

void Gifle::draw()
{

	for (Etudiant* e : etudiants) {
		app.window.draw(*e);
	}

	app.window.draw(chrono);
}

void Gifle::update()
{
	

	float timeBetweenWaves = 0.5;

	if (clock.getElapsedTime().asSeconds() - wave > timeBetweenWaves) {

		
		std::cout << rand() % (app.window.getSize().y - 180) + 100 << std::endl;
		if (wave % 7 == 1 || wave % 7 == 5) {
			etudiants.push_back(new NonMasque
			(sf::Vector2f(-rand() % 100 - 175, rand() % (app.window.getSize().y - 180) + 100), &app.window, 1, &deltaTime));
			etudiants.push_back(new Etudiant
			(sf::Vector2f(app.window.getSize().x + rand() % 100 + 175, rand() % (app.window.getSize().y - 180) + 100), &app.window, -1, &deltaTime));
		}
		else if (wave % 7 == 3 || wave % 7 == 6) {
			etudiants.push_back(new Etudiant
			(sf::Vector2f(-rand() % 100 - 175, rand() % (app.window.getSize().y - 180) + 100), &app.window, 1, &deltaTime));
			etudiants.push_back(new NonMasque
			(sf::Vector2f(app.window.getSize().x + rand() % 100 + 175, rand() % (app.window.getSize().y - 180) + 100), &app.window, -1, &deltaTime));
		}
		else {
		etudiants.push_back(new Etudiant
			(sf::Vector2f(-rand() % 100 - 175, rand() % (app.window.getSize().y - 180) + 100), &app.window, 1, &deltaTime));
		etudiants.push_back(new Etudiant
			(sf::Vector2f(app.window.getSize().x + rand() % 100 + 175, rand() % (app.window.getSize().y - 180) + 100), &app.window,-1, &deltaTime));
		}

		wave++;
		sort(etudiants.begin(), etudiants.end(), compareEtudiantPtr);
	}

	for (int i(etudiants.size()); i != 0;) {
		if (etudiants.size() == 0) break;
		--i;
		etudiants[i]->update();
		if (etudiants[i]->isOutOfBounds()) {
			etudiants.erase(etudiants.begin() + i);
			sort(etudiants.begin(), etudiants.end(), compareEtudiantPtr);
		}
	}

	//if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
	for (std::vector<Etudiant*>::iterator i(etudiants.end()); i != etudiants.begin();) {
		--i;
		(*i)->onClick();
	}
	//}

	chrono.update();
}


