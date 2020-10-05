#include "../header/Chrono.h"
#include<iostream>

Chrono::Chrono() {
}

Chrono::~Chrono() {
}

Chrono::Chrono(float _time, sf::Clock* _clock, AppData& data) {
	time = _time;
	clock = _clock;
	bar.setFillColor(sf::Color::Green);
	bar.setPosition(sf::Vector2f(20 + 9, data.window.getSize().y -20 - 9));
	tex = sf::Texture();
	tex.loadFromFile("../ressource/pile.png");
	spriteBatterie.setTexture(tex);
	//spriteBatterie.setPosition(20, data.window.getSize().y - 20 - tex.getSize().y);
	spriteBatterie.setPosition(20, 20);
	clock->restart();
}

void Chrono::update()
{
	bar.setSize(sf::Vector2f(51, - 483 * ((time - clock->getElapsedTime().asSeconds()) /time)));
}

void Chrono::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(spriteBatterie);
	target.draw(bar);
	
}