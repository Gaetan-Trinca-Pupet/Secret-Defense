#ifndef __GIFLE_H_
#define __GIFLE_H_

#include "../MiniJeu.h"
#include "./Passant.h"
#include "../../clickable.h"
#include "../../Chrono.h"

class Gifle : public MiniJeu {
private:

	virtual void draw();
	virtual void update();

	int wave;

	Chrono chrono;

	std::vector<Passant*> Passants;

public:
	Gifle(AppData& appData);
	virtual ~Gifle();
};



#endif