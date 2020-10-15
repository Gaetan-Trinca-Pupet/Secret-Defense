#ifndef __CHRONO_H_
#define __CHRONO_H_

#include <SFML/Graphics.hpp>
#include "miniJeu/MiniJeu.h"
<<<<<<< HEAD
=======
#include "Filled_arc.h"
>>>>>>> master
#include "AssetManager.h"

class Chrono : public sf::Drawable {
public:

	Chrono();
<<<<<<< HEAD
	Chrono(float _time, sf::Clock* _clock, sf::RenderWindow& window, AssetManager* _assetManager);
=======
	Chrono(float _time, sf::Clock* _clock, sf::RenderWindow& window);
>>>>>>> master
	virtual ~Chrono();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void update();

private:

	float time;
<<<<<<< HEAD
	AssetManager* assetManager;
	sf::Clock* clock;
	sf::RectangleShape bar;
	sf::Texture tex;
	sf::Sprite spriteBatterie;
=======
	//AssetManager* assetManager;
	sf::Clock* clock;
	Filled_arc arc;
	//sf::Texture tex;
	sf::CircleShape outline;
	float factor;
>>>>>>> master
};

#endif