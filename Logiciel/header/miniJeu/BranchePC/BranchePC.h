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
		std::vector<Prise*> tabPrise;
		Grabber::Grabber main = Grabber::Grabber(tabPrise);

	protected:
		virtual void setup();
		virtual void draw();
		virtual void update();
	public:
		BranchePC(AppData& appData);
		~BranchePC();
	};
}

#endif