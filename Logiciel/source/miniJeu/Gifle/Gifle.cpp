#include "../../../header/miniJeu/Gifle/Gifle.h"
#include <iostream>

bool compareEtudiantPtr(Etudiant* e1, Etudiant* e2)
{
	return (*e1 < *e2);
}

Gifle::Gifle(AppData& appData) : MiniJeu(appData) {
	isFinished = false;
	time = 15;
	chrono = Chrono(time, &clock, app.window);
	mouseIsAlreadyPressed = false;
}

Gifle::~Gifle() {

}

void Gifle::setup() {

	etudiants.push_back(new Etudiant(sf::Vector2f(0, 180), &app.window, 1, &deltaTime));
	etudiants.push_back(new Etudiant(sf::Vector2f(-200, app.window.getSize().y-250), &app.window, 1, &deltaTime));
	etudiants.push_back(new Etudiant(sf::Vector2f(app.window.getSize().x+10, 150), &app.window, -1, &deltaTime));
	etudiants.push_back(new NonMasque(sf::Vector2f(app.window.getSize().x+350, 210), &app.window, -1, &deltaTime));
	etudiants.push_back(new NonMasque(sf::Vector2f(-60, 100), &app.window, 1, &deltaTime));
	sort(etudiants.begin(), etudiants.end(), compareEtudiantPtr);

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

	for (int i(etudiants.size()); i != 0;) {
		if (etudiants.size() == 0) break;
		--i;
		etudiants[i]->update();
		if (etudiants[i]->isOutOfBounds())
			etudiants.erase(etudiants.begin() + i);
	}


	for (std::vector<Etudiant*>::iterator i(etudiants.end()); i != etudiants.begin();) {
		--i;
		(*i)->onClick();
	}


	chrono.update();
}


