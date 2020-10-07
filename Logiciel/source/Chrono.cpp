#include "../header/Chrono.h"

Chrono::Chrono() {
}

Chrono::~Chrono() {
}

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
}

void Chrono::update()
{
	//spriteBatterie.setTexture(tex);
	bar.setSize(sf::Vector2f(51, std::min(int(- 483 * ((time - clock->getElapsedTime().asSeconds()) /time)),0)));
}

void Chrono::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(spriteBatterie);
	target.draw(bar);
	
}