#ifndef __CHRONO_H_
#define __CHRONO_H_

#include <SFML/Graphics.hpp>
#include "miniJeu/MiniJeu.h"
#include "Filled_arc.h"
#include "AssetManager.h"

class Chrono : public sf::Drawable {
public:

	Chrono();
	Chrono(sf::RenderWindow& window);
	virtual ~Chrono();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void update();

	float getTimePassed();
	void setTempsMax(float _tempsMax);

private:


	sf::Clock clock;
	Filled_arc arc;
	sf::CircleShape outline;
	float factor;
	float tempsMax;
};

#endif