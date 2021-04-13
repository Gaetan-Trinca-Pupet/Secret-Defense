#ifndef __MENU__H_
#define __MENU__H_

#include <SFML/Graphics.hpp>

#include "../miniJeu/MiniJeu.h"
#include "MenusEnum.h"
#include "MenuPrincipal.h"
#include "MenuOptions.h"
#include "MenuGameOver.h"
#include "MenuScores.h"

namespace Menu{
	
	class Menu{
		
		private :
			AppData& app;
			sf::Sprite background;
			MenuPrincipal menuPrincipal;
			MenuOptions menuOptions;
			MenuGameOver menuGameOver;
			MenuScores menuScores;
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