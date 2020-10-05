#ifndef __MINI_JEU_ETEINDRE_
#define __MINI_JEU_ETEINDRE_

#include "../MiniJeu.h"
#include "Personnage.h"

namespace EteindrePC{
	class EteindrePC : public MiniJeu{
		private :
			Personnage laporte;
		protected :
			virtual void setup();
			virtual void draw();
			virtual void update();
		public :
			EteindrePC(AppData& appData);
	};
}
#endif