#include "../../../header/miniJeu/DistribMiniTests/DistribMiniTests.h"
#include <algorithm>

DisitribMiniTests::DisitribMiniTests(AppData& appData) : MiniJeu(appData)
{
	hand.setSprite(AssetManager::getTexture("../ressource/hand.png"));
	app.window.setMouseCursorVisible(false);

	nbMiniTests = 5;

	srand(std::time(NULL));

	chrono = Chrono(app.window);
	chrono.setTempsMax(11.0);

}

DisitribMiniTests::~DisitribMiniTests()
{
	for (MiniTest* i : miniTests) {
		delete i;
	}
}

void DisitribMiniTests::draw()
{
	app.window.draw(backGround);

	app.window.draw(throwZone);

	app.window.draw(chrono);

	for (Etudiant& e : etudiants) {
		app.window.draw(e);
	}
	
	for (MiniTest* i : miniTests) {
		app.window.draw(*i);
	}

	

	hand.draw(app.window);
}

void DisitribMiniTests::update()
{
	hand.update(app.window);
	chrono.update();

	for (unsigned m(0); m < miniTests.size(); ++m) {
		miniTests[m]->update();
		if (!miniTests[m]->canBeGrabbed()) {
			for (Etudiant& e : etudiants) {
				if (e.tryToCatch(miniTests[m]->getPosition())) {
					miniTests.erase(miniTests.begin()+ m);
				}
			}
		}
	}
}

void DisitribMiniTests::setup()
{
	throwZone.setSize(sf::Vector2f(380, 140));
	throwZone.setFillColor(sf::Color::Transparent);
	throwZone.setOutlineColor(sf::Color::Blue);
	throwZone.setOutlineThickness(6);
	throwZone.setOrigin(throwZone.getSize().x / 2, throwZone.getSize().y);
	throwZone.setPosition(app.window.getSize().x / 2, app.window.getSize().y);


	std::vector<sf::Vector2f> posVect = { sf::Vector2f(160, 100),  sf::Vector2f(130, 160),  sf::Vector2f(100, 230),
										  sf::Vector2f(680, 100),  sf::Vector2f(710, 160),  sf::Vector2f(740, 230) };
	unsigned nbEtudiants = 6;
	std::random_shuffle(posVect.begin(), posVect.end());

	for (unsigned i(0); i < nbEtudiants; ++i)
		etudiants.push_back(Etudiant(posVect[i]));


	for (unsigned i(0); i < nbMiniTests; ++i)
	{
		sf::Vector2f pos(app.window.getSize().x / 2  + (rand() % 21) - 10,
						(app.window.getSize().y - 70 + (rand() % 21) - 10));

		float rotation = (rand() % 31) - 15;
		if (rotation < 0) rotation += 360;

		miniTests.push_back(new MiniTest(pos, rotation, throwZone.getGlobalBounds(), &deltaTime, app.window));

		hand.add(miniTests.back());

	}
	std::reverse(miniTests.begin(), miniTests.end());

	backGround.setTexture(assetManager.getTexture("../ressource/DistribMiniTest/DistribCopie.png"));

}
