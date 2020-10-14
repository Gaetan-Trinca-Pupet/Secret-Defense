#ifndef __CHRONO_H_
#define __CHRONO_H_

#include <SFML/Graphics.hpp>
#include "miniJeu/MiniJeu.h"
#include "Filled_arc.h"
#include "AssetManager.h"

class Chrono : public sf::Drawable {
public:

	Chrono();
	Chrono(float _time, sf::Clock* _clock, sf::RenderWindow& window);
	virtual ~Chrono();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void update();

private:

	float time;
	//AssetManager* assetManager;
	sf::Clock* clock;
	Filled_arc arc;
	//sf::Texture tex;
	sf::CircleShape outline;
};

#endif