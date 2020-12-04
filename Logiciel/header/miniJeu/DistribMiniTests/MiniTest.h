#ifndef __MINITEST_H_
#define __MINITEST_H_

#include "../../Grabber.hpp"
#include "Etudiant.h"
#include "../../AssetManager.h"

class MiniTest : public Grabber::Grabbable
{
public:

	MiniTest();
	MiniTest(sf::Vector2f pos, float rotation, sf::FloatRect throwRange, float* _deltaTime, sf::RenderWindow& _window);

	virtual ~MiniTest();

	virtual bool canBeGrabbed();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void update();



private:

	bool isThrown;
	sf::FloatRect throwRange;
	float throwSpeed;
	float* deltaTime;

	sf::Vector2f lastPos;
	sf::Vector2f throwDir;

	sf::Vector2u winSize;

	sf::RenderTexture rTex;
};

#endif