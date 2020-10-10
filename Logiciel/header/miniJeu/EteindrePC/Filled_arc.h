#ifndef __MINI_JEU_ETEINDRE_FILLED_ARC_
#define __MINI_JEU_ETEINDRE_FILLED_ARC_

#include <string>

#include <SFML/Graphics.hpp>

namespace EteindrePC{
	class Filled_arc : public sf::Drawable{
		private:
			sf::Vertex point;
			unsigned int radius;
			unsigned int nbangles;
			float deg;
		public :
			Filled_arc(const sf::Vector2f& position = sf::Vector2f(),
					const sf::Color& col = sf::Color(),
					const unsigned int rad = 20, const unsigned int nbvert = 50);
			
			void draw(sf::RenderTarget& target, sf::RenderStates states) const;
			
			void setPosition(const sf::Vector2f& position);
			void setColor(const sf::Color& col);
			void setRadius(const unsigned rad );
			void setNBangles(const unsigned nba);
			void setDeg(const float& degre);
			
		private :
			static sf::Shader shader;
			static bool isLoaded;
	};
}

#endif