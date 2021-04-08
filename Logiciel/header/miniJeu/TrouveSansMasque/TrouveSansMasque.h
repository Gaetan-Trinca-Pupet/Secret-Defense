#ifndef __trouve_H_
#define __trouve_H_

#include "../MiniJeu.h"
#include "./Passant.h"
#include "../../clickable.h"
#include "../../Chrono.h"

namespace TrouveSansMasque
{

	class TrouveSansMasque : public MiniJeu
	{
	public:

		/**
		 * Constructeur de trouve.
		 *
		 * \param appData contiend es données utilse comme la fenêtr, difficulté, ect...
		 */
		TrouveSansMasque(AppData& appData);
		virtual ~TrouveSansMasque();


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
}

#endif