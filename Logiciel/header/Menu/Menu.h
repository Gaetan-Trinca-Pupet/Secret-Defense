#ifndef __MENU__H_
#define __MENU__H_

#include "../miniJeu/MiniJeu.h"
#include "Connexion.h"

namespace Menu{
	
	class Menu{
		
		private :
			AppData& app;
			Connexion connexion;
			void update();
			void draw();
		public :
			Menu(AppData& appData);
			void play();
		
	};
	
}

#endif