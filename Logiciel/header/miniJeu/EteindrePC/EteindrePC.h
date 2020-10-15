#ifndef __MINI_JEU_ETEINDRE_
#define __MINI_JEU_ETEINDRE_

#include <vector>
#include <cstdlib>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "../MiniJeu.h"
#include "Personnage.h"
#include "Mur.h"
#include "Table.h"
#include "../../Filled_arc.h"
#include "PC_bas.h"
#include "PC_haut.h"

namespace EteindrePC{
	class EteindrePC : public MiniJeu{
		private :
			Mur mur1;
			Mur mur2;
			Mur mur3;
			Table table1;
			Table table2;
			Table table3;
			Filled_arc rond;
			Personnage laporte;
			std::vector<PC_base*> pcs;
			sf::Clock clock;
			sf::Time tempsCouloir;
			int temps;
			virtual void setup();
			virtual void draw();
			virtual void update();
			void createPCs();
			void initPCs();
		public :
			EteindrePC(AppData& appData);
			~EteindrePC();
	};
}
#endif