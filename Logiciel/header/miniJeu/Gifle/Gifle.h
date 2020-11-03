#ifndef __GIFLE_H_
#define __GIFLE_H_

#include "../MiniJeu.h"
#include "./Etudiant.h"
#include "../../clickable.h"
#include "../../Chrono.h"

class Gifle : public MiniJeu {
private:

	virtual void setup();
	virtual void draw();
	virtual void update();
	//todo : handleevent
	bool mouseIsAlreadyPressed;
	int wave;

	Chrono chrono;

	std::vector<Etudiant*> etudiants;

public:
	Gifle(AppData& appData);
	virtual ~Gifle();
};



#endif