#ifndef __MENU__H_
#define __MENU__H_

#include <SFML/Graphics.hpp>

#include "../miniJeu/MiniJeu.h"
#include "MenusEnum.h"
#include "MenuPrincipal.h"
#include "MenuOptions.h"
#include "MenuGameOver.h"

namespace Menu{
	
	class Menu{
		
		private :
			AppData& app;
			//Connexion connexion;
			sf::Sprite background;
			MenuPrincipal menuPrincipal;
			MenuOptions menuOptions;
			MenuGameOver menuGameOver;
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