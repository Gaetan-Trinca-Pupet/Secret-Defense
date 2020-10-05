#ifndef __CHRONO_H_
#define __CHRONO_H_

#include <SFML/Graphics.hpp>
#include "./miniJeu/MiniJeu.h"

class Chrono : public sf::Drawable {
public:

	Chrono();
	Chrono(float _time, sf::Clock* _clock, AppData& data);
	virtual ~Chrono();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void update();

private:

	float time;
	sf::Clock* clock;
	sf::RectangleShape rect;
};

#endif