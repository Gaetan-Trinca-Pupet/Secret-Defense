#include "../header/Chrono.h"
#include <math.h>
#include <iostream>

Chrono::Chrono() {
}

Chrono::~Chrono() {
}

Chrono::Chrono(sf::RenderWindow& window) {

	arc.setRadius(80);
	arc.setPosition(sf::Vector2f(0.8,0.8));
	outline.setRadius(48);
	//outline.setOutlineThickness(8);
	outline.setOrigin(outline.getRadius(), outline.getRadius());
	outline.setPosition(window.getSize().x * (0.8/2+0.5), window.getSize().y * (0.2 / 2));

	factor = 0.3;
}

void Chrono::update()
{
	//spriteBatterie.setTexture(tex);
	if (tempsMax < clock.getElapsedTime().asSeconds()) return;

	arc.setDeg(3.14159265359 * 2 * (tempsMax - clock.getElapsedTime().asSeconds()) / tempsMax);

	arc.setColor(sf::Color(int(powf((clock.getElapsedTime().asSeconds()) / tempsMax, factor) * 255)
		, int(powf(((tempsMax - clock.getElapsedTime().asSeconds()) / tempsMax), factor) * 255)
		, 20));

	outline.setFillColor(sf::Color(int(powf((clock.getElapsedTime().asSeconds()) / tempsMax, factor) * 100)
		, int(powf(((tempsMax - clock.getElapsedTime().asSeconds()) / tempsMax), factor) * 100)
		, 20));
}

float Chrono::getTimePassed()
{
	return clock.getElapsedTime().asSeconds();
}

void Chrono::setTempsMax(float _tempsMax)
{
	tempsMax = _tempsMax;
}

void Chrono::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(outline);
	target.draw(arc);
}