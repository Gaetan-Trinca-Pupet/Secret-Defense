#ifndef __MINI_JEU_ETEINDRE_FILLED_ARC_
#define __MINI_JEU_ETEINDRE_FILLED_ARC_

#include <string>

#include <SFML/Graphics.hpp>

/**
*  @author Erwann Lubrano
*  Filled_arc permet de dessiner des secteurs angulaire 
*/
class Filled_arc : public sf::Drawable{
	private:
		sf::Vertex point;
		unsigned int radius;
		unsigned int nbangles;
		float deg;
	public :
	
		/**
		*  @brief constructeur de Filled_arc.
		*  @param position : la position du centre sur la feunetre.
		*  @param col : la couleur de remplissage.
		*  @param rad : le rayon.
		*  @param nbvert : le nombre maximal de angles générés par le geometry shader.
		*/
		Filled_arc(const sf::Vector2f& position = sf::Vector2f(),
				const sf::Color& col = sf::Color(),
				const unsigned int rad = 20, const unsigned int nbvert = 50);
		
		/**
		*  @brief méthode héritée de sf::Drawable.
		*/
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		
		/**
		*  @brief change la position
		*  @param position : nouvelle coordonnée du centre de l'objet.
		*/
		void setPosition(const sf::Vector2f& position);
		
		/**
		*  @brief change la couleur
		*  @param col : nouvelle couleur de remplissage.
		*/
		void setColor(const sf::Color& col);
		
		/**
		*  @brief change le rayon 
		*  @param rad : nouveau rayon (en nombre de pixel).
		*/
		void setRadius(const unsigned rad );
		
		/**
		*  @brief defini le nombre maximal d'angle généré par le geometry shader.
		*  @param nba : nouveau nombre maximal d'angle.
		*/
		void setNBangles(const unsigned nba);
		
		/**
		*  @brief defini l'angle de l'arc 
		*  @param degre : l'angle en radian
		*/
		void setDeg(const float& degre);
		
	private :
		static sf::Shader shader;
		static bool isLoaded;
};


#endif