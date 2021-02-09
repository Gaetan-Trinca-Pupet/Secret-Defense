#ifndef __MINITEST_H_
#define __MINITEST_H_

#include "../../Grabber.hpp"
#include "Etudiant.h"
#include "../../AssetManager.h"
#include <cmath>

class MiniTest : public Grabber::Grabbable
{
public:

	MiniTest();

	/**
	 * Constructeur de MiniTest.
	 * 
	 * \param pos position intiale
	 * \param rotation rotation initiale
	 * \param throwRange zone dans laquelle le mini test n'est pas en mode lancer et peux être attrapé
	 * \param _window fenêtre
	 */
	MiniTest(sf::Vector2f pos, float rotation, sf::FloatRect throwRange, sf::RenderWindow& _window);

	virtual ~MiniTest();

	virtual bool canBeGrabbed();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	/**
	 * Met a jour le mini test.
	 * 
	 */
	void update();



private:

	bool isThrown;
	sf::FloatRect throwRange;
	float throwSpeed;

	sf::Vector2f lastPos;
	sf::Vector2f throwDir;

	sf::Vector2f winSize;

	sf::RenderTexture rTex;
};

#endif
