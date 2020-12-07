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
#include "PC_bas.h"
#include "PC_haut.h"
#include "../../Chrono.h"


namespace EteindrePC{
	
	/**
	*  La class EteindrePC est un minijeu dans lequel il faut EteindrePC tous les PC puis sortir de la salle.
	*  Le temps est limité. Pour eviter trop d'attente le minijeu s'arrete au bout de 5 secondes dans le couloir.
	*  @author Erwann Lubrano
	*/
	
	class EteindrePC : public MiniJeu{
		
		
		private :
			Chrono chrono;
		
			Mur mur1;
			Mur mur2;
			Mur mur3;
			
			Table table1;
			Table table2;
			Table table3;
			
			Filled_arc rond;
			
			Personnage laporte;
			
			std::vector<PC_base*> pcs;
			
			
			/**
			*  @brief fonction appelée une fois au debut de play (heritée de MiniJeu) destinée à l'initialisation
			*/
			virtual void setup();
			
			/**
			*  @brief fonction appelée en boucle par play (heritée de MiniJeu) destinée à l'affichage
			*/
			virtual void draw();
			
			/**
			*  @brief fonction appelée en boucle par play (heritée de MiniJeu) destinée à tout sauf l'affichage
			*/
			virtual void update();
			
			/**
			*  @brief permet de créer les PCs à l'initialisation
			*/
			void createPCs();
			
			/**
			*  @brief permet d'allumé les Pcs à l'initialisation
			*/
			void initPCs();
			
			
		public :
		
			/**
			*  @brief constructeur
			*  constructeur de la class EteindrePC
			*  @param appData : contient les données communes à tous les minijeux.
			*/
			EteindrePC(AppData& appData);
			
			/**
			*  @brief destructeur
			*  destructeur de la class EteindrePC
			*/
			~EteindrePC();
			
			
	};
	
	
	
}
#endif