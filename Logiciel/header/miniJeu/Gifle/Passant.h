#ifndef __PASSANT_H_
#define __PASSANT_H_

#include "../../clickable.h"
#include "../../AssetManager.h"

class Passant : public Clickable
{

public:
	Passant(const sf::Vector2f& pos, sf::RenderWindow* w, float dir, bool isMasque, unsigned difficulty);
	virtual ~Passant();
	void update();
	bool isOutOfBounds();
	bool isMasked();
	bool isGifle();
	bool operator < (Passant& p2);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Sprite sprite;

	bool gifle;
	virtual void actionOnClick();
	float speed;
	float dir;
	bool masked;
	bool enFuite;
	sf::RenderWindow* window;

	sf::Clock clockPourDelaiFuite;

	sf::Clock clockPourDelaiAnimation;
};


#endif