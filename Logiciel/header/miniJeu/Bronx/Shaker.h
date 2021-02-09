#ifndef __SHAKER_H_
#define __SHAKER_H_

#include "../../Grabber.hpp"
#include "../../AssetManager.h"
#include <math.h>

class Shaker: public Grabber::Grabbable
{
public:
	Shaker();

	bool isShakingFinished();

	void startShaking();

	virtual void onGrab();
	virtual void updateOnGrab();

private:

	bool canBeShaked;
	sf::Vector2f lastpos;
	int shakeAmount;
	int shakeTreshold;

};

#endif
