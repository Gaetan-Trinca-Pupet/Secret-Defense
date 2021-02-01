#include "../../../header/miniJeu/DistribMiniTests/DistribMiniTests.h"
#include <algorithm>

DistribMiniTests::DistribMiniTests(AppData& appData) : MiniJeu(appData)
{

	tempsMax = (1 - (app.difficulty / (app.difficulty + 1.6))) * 5 + 7;

	hand.setSprite(AssetManager::getTexture("../ressource/hand.png"));
	app.window.setMouseCursorVisible(false);

	chrono = Chrono(app.window);
	chrono.setTempsMax(tempsMax);

	backGround.setTexture(AssetManager::getTexture("../ressource/DistribMiniTests/DistribCopie.png"));
}

DistribMiniTests::~DistribMiniTests()
{
	for (MiniTest* i : miniTests)
	{
		delete i;
	}

	app.window.setMouseCursorVisible(true);
}

void DistribMiniTests::draw()
{
	app.window.draw(backGround);

	app.window.draw(chrono);

	for (Etudiant& e : etudiants)
	{
		app.window.draw(e);
	}

	app.window.draw(throwZone);

	for (MiniTest* i : miniTests)
	{
		app.window.draw(*i);
	}

	hand.draw(app.window);
}

void DistribMiniTests::update()
{
	//si le temps est écoulé ou  tout les étudiants ont un mini test, finir le minijeu
	if (chrono.getTimePassed() > tempsMax || nbADistribuer == 0)
	{
		if (nbADistribuer != 0)
			app.lives -= 1;
		isFinished = true;
	}

	hand.update(app.window);

	chrono.update();

	for (int i(miniTests.size()); i != 0 && miniTests.size() != 0;)
	{
		--i;

		miniTests[i]->update();

		//si le mini test est lancé
		if (!miniTests[i]->canBeGrabbed())
		{

			hand.remove(miniTests[i]);

			for (Etudiant& e : etudiants)
			{
				//si l'étudiant e peux attraper le minitest, le supprimer
				if (e.tryToCatch(miniTests[i]->getPosition()))
				{
					delete miniTests[i];
					miniTests.erase(miniTests.begin() + i);
					--nbADistribuer;
					break;
				}
			}
		}
	}
}

void DistribMiniTests::setup()
{
	srand(std::time(NULL));

	//initialisation de la délimitation de la zone de lancer
	throwZone.setSize(sf::Vector2f(180, 125));
	throwZone.setFillColor(sf::Color::Transparent);
	throwZone.setOutlineColor(sf::Color::Red);
	throwZone.setOutlineThickness(6);
	throwZone.setOrigin(throwZone.getSize().x / 2, throwZone.getSize().y);
	throwZone.setPosition(app.window.getView().getSize().x / 2, app.window.getView().getSize().y);

	nbADistribuer = 4 + (app.difficulty < 2 ? app.difficulty : 2);

	creerEtudiants();

	creerMiniTests();
}

void DistribMiniTests::creerEtudiants()
{
	std::vector<unsigned> numEtus = { 0, 1, 2, 3, 4, 5 };
	std::random_shuffle(numEtus.begin(), numEtus.end());


	for (unsigned i(0); i < nbADistribuer; ++i)
		etudiants.push_back(Etudiant(numEtus[i]));
	std::sort(etudiants.begin(), etudiants.end());
}

void DistribMiniTests::creerMiniTests()
{
	unsigned short nbMiniTests = nbADistribuer + (app.difficulty < 2 ? 2 - app.difficulty : 0);


	for (unsigned i(0); i < nbMiniTests; ++i)
	{
		//générer une position aléatoire
		sf::Vector2f pos(app.window.getView().getSize().x / 2 + (rand() % 21) - 10,
			(app.window.getView().getSize().y - 70 + (rand() % 21) - 10));

		//générer une rotation aléatoire
		float rotation = (rand() % 21) - 10;
		if (rotation < 0) rotation += 360;

		miniTests.push_back(new MiniTest(pos, rotation, throwZone.getGlobalBounds(), app.window));

		hand.add(miniTests.back());

	}
	std::reverse(miniTests.begin(), miniTests.end());
}
