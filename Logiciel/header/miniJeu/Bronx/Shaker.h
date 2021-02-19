#ifndef __SHAKER_H_
#define __SHAKER_H_

#include "../../GravityAffected.h"
#include "../../AssetManager.h"
#include <math.h>

class Shaker: public GravityAffected
{
public:
	Shaker(sf::RenderWindow* w);
	virtual ~Shaker();

	bool isShakingFinished();

	void startShaking();

	virtual void onGrab();
	virtual void updateOnGrab();


private:

	sf::RenderWindow* window;
	bool canBeShaked;
	sf::Vector2f lastpos;
	int shakeAmount;
	int shakeTreshold;

};

#endif
