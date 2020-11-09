#ifndef __PASSANT_H_
#define __PASSANT_H_

#include "../../clickable.h"

class Passant : public Clickable {
protected:

	bool isGifle;
	virtual void actionOnClick();
	float* deltaTime;
	int speed;
	float dir;



public:
	Passant(const sf::Vector2f& pos, sf::RenderWindow* w, float dir, float* _deltaTime);
	virtual ~Passant();
	void update();
	bool isOutOfBounds();

};

class NonMasque : public Passant {
private:
	virtual void actionOnClick();
public:
	NonMasque(const sf::Vector2f& pos, sf::RenderWindow* w, float dir, float* _deltaTime);
	virtual ~NonMasque();

};


#endif