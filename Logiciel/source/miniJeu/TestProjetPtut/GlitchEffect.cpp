#include "../../../header/miniJeu/TestProjetPtut/GlitchEffect.h"


TestProjetPtut::GlitchEffect::GlitchEffect(){
	((sf::Time*)((void*)this))->operator=(*((sf::Time*)((void*)this))-sf::Time(sf::seconds(100)));
	states.shader = &shader;
	states.texture = &texture;
	if(!isLoaded){
		shader.loadFromFile("../ressource/shaders/wave.vert","../ressource/shaders/blur.frag");
		isLoaded = true;
	}
}

void TestProjetPtut::GlitchEffect::draw(sf::RenderWindow& window){
	window.clear();
	constexpr float x = 10.0;
	constexpr float y = 8.0;
	shader.setUniform("wave_phase", clock.getElapsedTime().asSeconds()*10);
    shader.setUniform("wave_amplitude", sf::Vector2f(x * 30, y * 5));
    shader.setUniform("blur_radius", (x + y) * 0.08f);
	sf::Sprite sprite(texture);
	window.draw(sprite,states);
}

bool TestProjetPtut::GlitchEffect::isActive()const{
	return clock.getElapsedTime().asSeconds() < 0.4;
}

void TestProjetPtut::GlitchEffect::start(sf::RenderWindow& window){
	window.display();
	sf::Vector2u windowSize = window.getSize();
	texture.create(windowSize.x, windowSize.y);
	texture.update(window);
	
	clock.restart();
}

sf::Shader TestProjetPtut::GlitchEffect::shader;
bool TestProjetPtut::GlitchEffect::isLoaded;