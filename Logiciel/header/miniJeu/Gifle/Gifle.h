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

	int wave;
	float timeBetweenWaves;

	int erreurCpt;

	Chrono chrono;
	std::vector<Passant*> passants;


};



#endif