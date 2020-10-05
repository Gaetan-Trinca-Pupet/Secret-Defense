#ifndef __BRANCHEPC_H_
#define __BRANCHEPC_H_

#include <vector>
#include "../MiniJeu.h"
#include "Prise.h"

namespace BranchePC
{
	class BranchePC : public MiniJeu
	{
	private:
		std::vector<Prise*> tabPrise;

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