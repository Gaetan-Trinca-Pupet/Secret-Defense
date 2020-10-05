#ifndef __MINI_JEU_ETEINDRE_
#define __MINI_JEU_ETEINDRE_

#include "../MiniJeu.h"

namespace EteindrePC{
	class EteindrePC : public MiniJeu{
		protected :
			virtual void setup();
			virtual void draw();
			virtual void update();
		public :
			EteindrePC(AppData& appData);
	};
}
#endif