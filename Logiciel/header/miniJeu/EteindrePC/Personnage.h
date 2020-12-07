#ifndef __MINI_JEU_ETEINDRE_PERSONNAGE_H
#define __MINI_JEU_ETEINDRE_PERSONNAGE_H

#include <vector>
#include <utility>

#include <SFML/Graphics.hpp>
#include "CollisionBox.h"
#include "../../Controles.h"

namespace EteindrePC{
	
	/**
	*  @author Erwann Lubrano
	*  L'enumeration Direction sert à connaitre la direction vers laquelle le Personnage est tourné.
	*/
	enum Direction{
		Bas=0,
		Gauche=1,
		Droite=2,
		Haut=3
	};
	
	/**
	*  @author Erwann Lubrano
	*  La class Personnage permet de créer un Personnage controlable avec les touche Z,Q,S,D.
	*/
	class Personnage{
		
		
		private :
		
			Controles controles;
		
			sf::Vector2f position;
			
			sf::Sprite sprite;
			
			sf::Clock clock;
			
			Direction direction;
			
			sf::Texture texture;
			unsigned char sprite_x;
			
			std::vector<CollisionBox*> collisionList;
			
		public :
		
			/**
			*  @brief constructeur 
			*  Constructeur de Personnage
			*/
			Personnage();
			
			/**
			*  @brief fonction permettant de deplacer (avec les touches Z,Q,S,D) le Personnage si possible et de changé sa direction.
			*/
			void update();
			
			/**
			*  @brief fonction permettant d'afficher le Personnage
			*  @param window la feunetre dans laquelle le Personnage doit etre affiché
			*/
			void draw(sf::RenderWindow& window);
			
			/**
			*  @brief ajoute une zone ou le joueur ne pourra pas aller.
			*  @param collisionBox : boite de collision. 
			*/
			void addCollisionBox(CollisionBox& collisionBox);
			
			/**
			*  @brief recupère la position et la direction du Personnage
			*  @return la pair renvoyée contient les adresses de la position (first) et de la direction (second) 
			*/
			std::pair<sf::Vector2f*,EteindrePC::Direction*> getPersoView();
			
			
	};
	
	
}


#endif