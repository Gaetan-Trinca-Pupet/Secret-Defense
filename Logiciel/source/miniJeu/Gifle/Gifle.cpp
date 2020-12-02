#include "../../../header/miniJeu/Gifle/Gifle.h"
#include <iostream>
#include <time.h>

bool comparePassantPtr(Passant* e1, Passant* e2)
{
	return (*e1 < *e2);
}

Gifle::Gifle(AppData& appData) : MiniJeu(appData) {
	isFinished = false;
	tempsMax = 20;
	chrono = Chrono(app.window);
	chrono.setTempsMax(tempsMax);
	wave = 0;
	srand(std::time(NULL));
}

Gifle::~Gifle() {
	for (int i(Passants.size()); i != 0;) {
		--i;
		Passants.erase(Passants.begin() + i);
	}
}

void Gifle::draw()
{

	for (Passant* e : Passants) {
		app.window.draw(*e);
	}

	app.window.draw(chrono);
}

void Gifle::update()
{

	float timeBetweenWaves = 0.5;

	if (chrono.getTimePassed() - wave > timeBetweenWaves) {

		if (wave % 7 == 1 || wave % 7 == 5) {
			Passants.push_back(new NonMasque
			(sf::Vector2f(-rand() % 100 - 175, rand() % (app.window.getSize().y - 180) + 100), &app.window, 1, &deltaTime));
			Passants.push_back(new Passant
			(sf::Vector2f(app.window.getSize().x + rand() % 100 + 175, rand() % (app.window.getSize().y - 180) + 100), &app.window, -1, &deltaTime));
		}
		else if (wave % 7 == 3 || wave % 7 == 6) {
			Passants.push_back(new Passant
			(sf::Vector2f(-rand() % 100 - 175,
				           rand() % (app.window.getSize().y - 180) + 100),&app.window, 1, &deltaTime));
			Passants.push_back(new NonMasque
			(sf::Vector2f(app.window.getSize().x + rand() % 100 + 175, rand() % (app.window.getSize().y - 180) + 100), &app.window, -1, &deltaTime));
		}
		else {
			Passants.push_back(new Passant
				(sf::Vector2f(-rand() % 100 - 175, rand() % (app.window.getSize().y - 180) + 100), &app.window, 1, &deltaTime));
			Passants.push_back(new Passant
				(sf::Vector2f(app.window.getSize().x + rand() % 100 + 175, rand() % (app.window.getSize().y - 180) + 100), &app.window,-1, &deltaTime));
		}

		wave++;
		sort(Passants.begin(), Passants.end(), comparePassantPtr);
	}

	for (int i(Passants.size()); i != 0;) {
		if (Passants.size() == 0) break;
		--i;
		Passants[i]->update();

		if (Passants[i]->isOutOfBounds()) {
			Passants.erase(Passants.begin() + i);
			sort(Passants.begin(), Passants.end(), comparePassantPtr);
		}
	}

	chrono.update();
}


