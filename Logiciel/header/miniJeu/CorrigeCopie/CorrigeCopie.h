#ifndef __CORRIGECOPIE_H_
#define __CORRIGECOPIE_H_

#include "BoutonVF.h"
#include "../MiniJeu.h"
#include "../../Chrono.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <map>
#include <ctime>
#include <fstream>

namespace CorrigeCopie
{
	struct Reponse
	{
		bool VF;
		sf::Text question;
		sf::Text reponse;

		unsigned nbligne;

		bool isCorrect;

		Reponse()
		{
			nbligne = 1;
			isCorrect = false;
		}
	};

	class CorrigeCopie : public MiniJeu
	{
	private :
		Chrono chrono;
		int posCamera;

		unsigned sizeFeuille;
		sf::RectangleShape feuille;

		sf::Font font;
		std::vector<Reponse> tabLibelle;
		std::vector<std::pair<BoutonVF*,BoutonVF*>> tabBouton;

		void computeTabText();
	protected:
		virtual void setup();
		virtual void draw();
		virtual void update();

	public:
		CorrigeCopie(AppData& appData);
		~CorrigeCopie();
	};
}




#endif
