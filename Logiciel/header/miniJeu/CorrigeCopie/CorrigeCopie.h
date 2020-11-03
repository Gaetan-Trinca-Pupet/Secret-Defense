#ifndef __CORRIGECOPIE_H_
#define __CORRIGECOPIE_H_

#include "../MiniJeu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <map>
#include <ctime>

namespace  CorrigeCopie
{
	class CorrigeCopie : public MiniJeu
	{
	private :
		int posCamera;

		unsigned sizeFeuille;
		sf::RectangleShape feuille;

		sf::Font font;
		std::vector<std::pair<bool,std::pair<sf::Text,sf::Text>>> tabLibelle;



		float tempsMax;
		float tempsPasse;
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