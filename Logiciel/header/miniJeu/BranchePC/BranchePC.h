#ifndef __BRANCHEPC_H_
#define __BRANCHEPC_H_

#include <vector>
#include <cstdlib>
#include <SFML/Window.hpp>
#include "../MiniJeu.h"
#include "Prise.h"
#include "../../Grabber.hpp"

namespace BranchePC
{
	class BranchePC : public MiniJeu
	{
	private:
		unsigned short nbPrise;

		Grabber::Grabber main;
		std::vector<Prise*> tabPrise;

		sf::Sprite background;
		sf::Texture backImage;
		

	protected:
		virtual void setup();
		virtual void draw();
		virtual void update();
	public:
		BranchePC(AppData& appData);
		virtual ~BranchePC();
	};
}

#endif