#include "../header/Chrono.h"

Chrono::Chrono() {
}

Chrono::~Chrono() {
}

Chrono::Chrono(float _time, sf::Clock* _clock, sf::RenderWindow& window) {
	time = _time;
	clock = _clock;
	arc.setColor(sf::Color::Green);
	arc.setRadius(30);
	arc.setPosition(sf::Vector2f(0.9,0.9));
	clock->restart();
}

void Chrono::update()
{
	//spriteBatterie.setTexture(tex);
	arc.setDeg(3.14159265359 * 2 * (time - clock->getElapsedTime().asSeconds()) / time);
}
void Chrono::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(arc);
	
}