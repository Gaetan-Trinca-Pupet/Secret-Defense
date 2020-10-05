#include "../header/Chrono.h"


Chrono::Chrono() {
}

Chrono::~Chrono() {
}

Chrono::Chrono(float _time, sf::Clock* _clock, AppData& data) {
	time = _time;
	clock = _clock;
	rect.setFillColor(sf::Color::Green);
	//rect.setOrigin(sf::Vector2f(0, 483));
	rect.setPosition(sf::Vector2f(9 + 20, data.window.getSize().y-(9 + 20)));
	clock->restart();
}

void Chrono::update()
{
	rect.setSize(sf::Vector2f(51, /*483*/ -400 * ((time - clock->getElapsedTime().asSeconds()) /time)));
}

void Chrono::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rect, states);
}