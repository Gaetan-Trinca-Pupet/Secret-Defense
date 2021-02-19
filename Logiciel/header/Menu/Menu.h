#ifndef __MENU__H_
#define __MENU__H_

#include "../miniJeu/MiniJeu.h"
#include "Connexion.h"
#include "MenusEnum.h"
#include "MenuPrincipal.h"

namespace Menu{
	
	class Menu{
		
		private :
			AppData& app;
			Connexion connexion;
			MenuPrincipal menuPrincipal;
			Menus menu;
			bool finished;
			void update();
			void draw();
		public :
			Menu(AppData& appData);
			void play();
			Menus getMenu()const;
			void setMenu(const Menus m);
		
	};
	
}

#endif