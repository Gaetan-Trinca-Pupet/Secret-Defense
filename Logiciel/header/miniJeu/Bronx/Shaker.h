#ifndef __SHAKER_H_
#define __SHAKER_H_

#include "../../GravityAffected.h"
#include "../../AssetManager.h"
#include "Verre.h"
#include <math.h>

class Shaker: public GravityAffected
{
public:
	Shaker(sf::RenderWindow* w);
	virtual ~Shaker();

	bool isShakingFinished();

	void startShaking();
    void startFilling();

    void fillUp(std::vector<Verre>& verres);

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
    std::vector<sf::FloatRect> hitBoxesToFill;

};

#endif
