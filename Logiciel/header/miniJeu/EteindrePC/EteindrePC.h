#ifndef __MINI_JEU_ETEINDRE_
#define __MINI_JEU_ETEINDRE_

#include "../MiniJeu.h"
#include "Personnage.h"
#include "Mur.h"
#include "Table.h"

namespace EteindrePC{
	class EteindrePC : public MiniJeu{
		private :
			Mur mur1;
			Mur mur2;
			Mur mur3;
			Table table1;
			Table table2;
			Table table3;
			Personnage laporte;
			virtual void setup();
			virtual void draw();
			virtual void update();
		public :
			EteindrePC(AppData& appData);
	};
}
#endif