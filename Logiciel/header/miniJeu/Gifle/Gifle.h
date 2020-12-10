#ifndef __GIFLE_H_
#define __GIFLE_H_

#include "../MiniJeu.h"
#include "./Passant.h"
#include "../../clickable.h"
#include "../../Chrono.h"

class Gifle : public MiniJeu
{
public:

	/**
	 * Constructeur de Gifle.
	 *
	 * \param appData contiend es données utilse comme la fenêtr, difficulté, ect...
	 */
	Gifle(AppData& appData);
	virtual ~Gifle();


private:
	virtual void draw();
	virtual void update();

	/**
	 * Creer un passant pour coin de l'écran, dont un non masqué.
	 * 
	 */
	void creerPassants();

	float timeBetweenWaves;

	int erreurCpt;

	Chrono chrono;

	sf::Sprite background;

	sf::Clock clockPourDelaiVagues;
	std::vector<Passant> passants;


};

#endif