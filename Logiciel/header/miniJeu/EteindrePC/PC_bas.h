#ifndef __MINI_JEU_ETEINDRE_PC_BAS_
#define __MINI_JEU_ETEINDRE_PC_BAS_

#include <SFML/Graphics.hpp>
#include "PC_base.h"

namespace EteindrePC{
	
	/**
	*  @author Erwann Lubrano
	*  PC_bas est la class des PC que le Personnage pourra eteindre/allumé quand il est tourné vers le bas.
	*/
	class PC_bas : public PC_base{
		
		
		private :
		
			/**
			*  @brief permet de savoir si le Personnage regarde le PC.
			*  @return renvoie true si le personnage regarde le PC sinon renvoie false
			*/
			bool isPersonnageLookingAt();
			
			/**
			*  @brief dessine le PC quand il est allumé
			*  @param window : la feunetre où afficher le PC
			*/
			void drawWhenIsOn(sf::RenderWindow& window);
			
			/**
			*  @brief dessine le PC quand il est éteint
			*  @param window : la feunetre où afficher le PC
			*/
			void drawWhenIsOff(sf::RenderWindow& window);
			
		public :
		
	};
	
	
}


#endif