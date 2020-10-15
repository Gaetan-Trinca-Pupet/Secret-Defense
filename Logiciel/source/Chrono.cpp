#include "../header/Chrono.h"
<<<<<<< HEAD
=======
#include <math.h>
#include <iostream>
>>>>>>> master

Chrono::Chrono() {
}

Chrono::~Chrono() {
}

<<<<<<< HEAD
Chrono::Chrono(float _time, sf::Clock* _clock, sf::RenderWindow& window, AssetManager* _assetManager) {
	assetManager = _assetManager;
	time = _time;
	clock = _clock;
	bar.setFillColor(sf::Color::Green);
	bar.setPosition(sf::Vector2f(20 + 9, window.getSize().y -20 - 9));
	tex.loadFromFile("../ressource/pile.png");
	spriteBatterie.setTexture(assetManager->getTexture("../ressource/pile.png"));
	spriteBatterie.setPosition(20, window.getSize().y - 20 - tex.getSize().y);
	clock->restart();
=======
Chrono::Chrono(float _time, sf::Clock* _clock, sf::RenderWindow& window) {
	time = _time;
	clock = _clock;
	arc.setRadius(80);
	arc.setPosition(sf::Vector2f(0.8,0.8));
	outline.setRadius(48);
	//outline.setOutlineThickness(8);
	outline.setOrigin(outline.getRadius(), outline.getRadius());
	outline.setPosition(window.getSize().x * (0.8/2+0.5), window.getSize().y * (0.2 / 2));
	clock->restart();

	factor = 0.3;
>>>>>>> master
}

void Chrono::update()
{
	//spriteBatterie.setTexture(tex);
<<<<<<< HEAD
	bar.setSize(sf::Vector2f(51, std::min(int(- 483 * ((time - clock->getElapsedTime().asSeconds()) /time)),0)));
}

void Chrono::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(spriteBatterie);
	target.draw(bar);
	
=======
	if (time - clock->getElapsedTime().asSeconds() < 0.001) return;

	arc.setDeg(3.14159265359 * 2 * (time - clock->getElapsedTime().asSeconds()) / time);

	arc.setColor(sf::Color(int(powf((clock->getElapsedTime().asSeconds()) / time, factor) * 255)
		, int(powf(((time - clock->getElapsedTime().asSeconds()) / time), factor) * 255)
		, 20));

	outline.setFillColor(sf::Color(int(powf((clock->getElapsedTime().asSeconds()) / time, factor) * 100)
		, int(powf(((time - clock->getElapsedTime().asSeconds()) / time), factor) * 100)
		, 20));
}
void Chrono::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(outline);
	target.draw(arc);
>>>>>>> master
}