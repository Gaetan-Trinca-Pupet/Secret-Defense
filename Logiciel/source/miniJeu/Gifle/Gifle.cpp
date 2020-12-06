#include "../../../header/miniJeu/Gifle/Gifle.h"
#include <iostream>
#include <time.h>

bool comparePassantPtr(Passant* e1, Passant* e2)
{
	return (*e1 < *e2);
}

Gifle::Gifle(AppData& appData) : MiniJeu(appData)
{
	chrono = Chrono(app.window);
	chrono.setTempsMax(16);
	srand(std::time(NULL));

	erreurCpt = app.difficulty < 3 ? 3 - app.difficulty : 0;
	timeBetweenWaves = 2;
}

Gifle::~Gifle()
{
	for (int i(passants.size()); i != 0;)
	{
		--i;
		delete passants[i];
	}
}

void Gifle::draw()
{

	for (Passant* e : passants)
	{
		app.window.draw(*e);
	}

	app.window.draw(chrono);
}

void Gifle::update()
{
	if (chrono.getTimePassed() > chrono.getTempsMax() )
		isFinished = true;

	if (passants.size() == 0 || chrono.getTimePassed() - wave * timeBetweenWaves > timeBetweenWaves)
	{

		creerPassants();

		++wave;
		sort(passants.begin(), passants.end(), comparePassantPtr);
	}

	for (int i(passants.size()); i != 0 && passants.size() != 0;)
	{
		--i;
		passants[i]->update();

		if (passants[i]->isOutOfBounds())
		{
			if ( (!passants[i]->isMasked() && !passants[i]->isGifle()) ||
			     ( passants[i]->isMasked() &&  passants[i]->isGifle() && erreurCpt <= 0))
			{
				app.lives -= 1;
				isFinished = true;
			}
			
			delete passants[i];
			passants.erase(passants.begin() + i);
		}
	}

	chrono.update();
}


void Gifle::creerPassants()
{

	int numPasdeMasque(rand() % 4);
	unsigned cpt(0);

	sf::Vector2f pos;

	//haut à gauche
	pos = sf::Vector2f(-200, 100);
	pos.x -= rand() % 100;
	pos.y += rand() % (((app.window.getSize().y - 200) / 2) - 10);
	passants.push_back(new Passant(pos, &app.window, 1, cpt++ != numPasdeMasque, app.difficulty));
	//bas à gauche
	pos = sf::Vector2f(-200, app.window.getSize().y - 100);
	pos.x -= rand() % 100;
	pos.y -= rand() % (((app.window.getSize().y - 200) / 2) + 10);
	passants.push_back(new Passant(pos, &app.window, 1,cpt++ != numPasdeMasque, app.difficulty));

	//haut à droite
	pos = sf::Vector2f(app.window.getSize().x + 200, 100);
	pos.x += rand() % 100;
	pos.y += rand() % (((app.window.getSize().y - 200) / 2) - 10);
	passants.push_back(new Passant(pos, &app.window, -1, cpt++ != numPasdeMasque, app.difficulty));

	//bas à droite
	pos = sf::Vector2f(app.window.getSize().x + 200, app.window.getSize().y - 100);
	pos.x += rand() % 100;
	pos.y -= rand() % (((app.window.getSize().y - 200) / 2) + 10);
	passants.push_back(new Passant(pos, &app.window, -1, cpt++ != numPasdeMasque, app.difficulty));


}


