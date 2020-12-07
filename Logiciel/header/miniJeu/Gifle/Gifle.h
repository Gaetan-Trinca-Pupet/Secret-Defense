#ifndef __GIFLE_H_
#define __GIFLE_H_

#include "../MiniJeu.h"
#include "./Passant.h"
#include "../../clickable.h"
#include "../../Chrono.h"

class Gifle : public MiniJeu
{
public:
	Gifle(AppData& appData);
	virtual ~Gifle();


private:
	virtual void draw();
	virtual void update();

	void creerPassants();

	float timeBetweenWaves;

	int erreurCpt;

	Chrono chrono;

	sf::Sprite background;

	sf::Sprite cursor;

	sf::Clock clockPourDelaiVagues;
	std::vector<Passant*> passants;


};



#endif