#ifndef __CHRONO_H_
#define __CHRONO_H_

#include <SFML/Graphics.hpp>
#include "miniJeu/MiniJeu.h"
#include "AssetManager.h"

class Chrono : public sf::Drawable {
public:

	Chrono();
	Chrono(float _time, sf::Clock* _clock, sf::RenderWindow& window, AssetManager* _assetManager);
	virtual ~Chrono();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void update();

private:

	float time;
	AssetManager* assetManager;
	sf::Clock* clock;
	sf::RectangleShape bar;
	sf::Texture tex;
	sf::Sprite spriteBatterie;
};

#endif