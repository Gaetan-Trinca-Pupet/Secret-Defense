#ifndef __ETUDIANT_H_
#define __ETUDIANT_H_

#include "../../clickable.h"

class Etudiant : public Clickable {
protected:

	bool isGifle;
	virtual void actionOnClick();
	float* deltaTime;
	float speed;
	float dir;



public:
	Etudiant(const sf::Vector2f& pos, sf::RenderWindow* w, float dir, float* _deltaTime);
	virtual ~Etudiant();
	void update();
	bool isOutOfBounds();

};

class NonMasque : public Etudiant {
private:
	virtual void actionOnClick();
public:
	NonMasque(const sf::Vector2f& pos, sf::RenderWindow* w, float dir, float* _deltaTime);
	virtual ~NonMasque();

};


#endif