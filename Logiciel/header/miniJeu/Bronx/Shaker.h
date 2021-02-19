#ifndef __SHAKER_H_
#define __SHAKER_H_

#include "../../Grabber.hpp"
#include "../../AssetManager.h"
#include <math.h>

class Shaker: public Grabber::Grabbable
{
public:
	Shaker(sf::RenderWindow* w);
	virtual ~Shaker();

	bool isShakingFinished();

	void startShaking();
    void startFilling();

    void fillUp();

	virtual void onGrab();
	virtual void updateOnGrab();
    virtual void onRelease();

private:

	sf::RenderWindow* window;
	bool canBeShaked;
    bool canFill;
	sf::Vector2f lastpos;
	int shakeAmount;
	int shakeTreshold;

protected:
    std::vector<sf::RectangleShape*> verresToFill;

};

#endif
