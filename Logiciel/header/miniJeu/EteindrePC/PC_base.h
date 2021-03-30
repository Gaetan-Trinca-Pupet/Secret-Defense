#ifndef __MINI_JEU_ETEINDRE_PC_BASE_
#define __MINI_JEU_ETEINDRE_PC_BASE_

#include <utility>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Personnage.h"
#include "../../AssetManager.h"

namespace EteindrePC{
	
	/**
	*  @author Erwann Lubrano
	*  la class PC_base est une class abstraite permettant 
	*/
	class PC_base{
		
		
		private :
		
			sf::Clock clock;
			
			bool notFirstTime;
			
			
		protected :
		
			sf::Vector2f position;
			
			bool on;
			
			std::pair<sf::Vector2f*,EteindrePC::Direction*> persoView;
			
			/**
			*  @brief permet de savoir si le Personnage regarde le PC.
			*  @return renvoie true si le personnage regarde le PC sinon renvoie false
			*/
			virtual bool isPersonnageLookingAt()=0;
			
			/**
			*  @brief dessine le PC quand il est allumé
			*  @param window : la feunetre où afficher le PC
			*/
			virtual void drawWhenIsOn(sf::RenderWindow& window)=0;
			
			/**
			*  @brief dessine le PC quand il est éteint
			*  @param window : la feunetre où afficher le PC
			*/
			virtual void drawWhenIsOff(sf::RenderWindow& window)=0;
			
		public :
		
			/**
			*  @brief getter de on
			*  @return renvoie true si le PC est allumé sinon renvoie false.
			*/
			bool isOn() const;
			
			/**
			*  @brief setter de on
			*  @param b : true si le PC doit etre allumé, sinon false.
			*/
			void setOn(bool b);
			
			/**
			*  @brief actualise l'etat du PC
			*/
			void update();
			
			/**
			*  @brief affiche le PC
			*  @param window : la feunetre où le PC doit etre allumé
			*/
			void draw(sf::RenderWindow& window);
			
			/**
			*  @brief setter de persoView
			*  @param pView : une paire contenant la position (first), position(second)
			*/
			void setPersoView(const std::pair<sf::Vector2f*,EteindrePC::Direction*>& pView);
			
			/**
			*  @brief setter de position
			*  @param pos : position voulue.
			*/
			void setPosition(const sf::Vector2f& pos);
			
			/**
			*  @brief constructeur de PC_base
			*/
			PC_base();
			
			virtual ~PC_base();
			
	};
	
	
}


#endif