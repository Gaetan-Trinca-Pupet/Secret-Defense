#ifndef __CHRONO_H_
#define __CHRONO_H_

#include <SFML/Graphics.hpp>
#include "Filled_arc.h"
#include "AssetManager.h"

class Chrono : public sf::Drawable {
public:

	Chrono();

	/**
	 * Constructeur de Chrono.
	 * 
	 * \param window la fenêtre permet au chrono de s'afficher au bon endroit
	 */
	Chrono(sf::RenderWindow& window);
	virtual ~Chrono();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	/**
	 * Met a jour le chrono.
	 * 
	 */
	void update();

	/**
	 * 
	 * \return le temps écoulé depuis la création.
	 */
	float getTimePassed();

	/**
	 * Permet d'indiquer la durée du chrono.
	 * 
	 * \param _tempsMax durée du chrono
	 */
	void setTempsMax(float _tempsMax);

	/**
	 * 
	 * \return durée du chrono
	 */
	float getTempsMax();

private:


	sf::Clock clock;
	Filled_arc arc;
	sf::CircleShape outline;
	float factor;
	float tempsMax;
};

#endif