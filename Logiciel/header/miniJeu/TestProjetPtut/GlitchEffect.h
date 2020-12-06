#ifndef __TEST_PROJET_PTUT__GLITCH_EFFECT_H_
#define __TEST_PROJET_PTUT__GLITCH_EFFECT_H_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace TestProjetPtut{
	class GlitchEffect{
		private:
			sf::Clock clock;
			sf::Texture texture;
			sf::RenderStates states;
			static sf::Shader shader;
			static bool isLoaded;
		public:
			GlitchEffect();
			void draw(sf::RenderWindow& window);
			bool isActive()const;
			void start(sf::RenderWindow& window);
	};
}

#endif