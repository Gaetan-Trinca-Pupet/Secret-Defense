#include "../header/Filled_arc.h"

sf::Shader Filled_arc::shader;
bool Filled_arc::isLoaded;

Filled_arc::Filled_arc(const sf::Vector2f& position, const sf::Color& col, const unsigned int rad, const unsigned int nba)
		: point(position,col), radius(rad), nbangles(nba), deg(2*3.14159265358979323846){
	if(!isLoaded){
		constexpr char vertexShaderFilename[] = "../ressource/shaders/filled_arc.vert";
		constexpr char geometryShaderFilename[] = "../ressource/shaders/filled_arc.geom";
		constexpr char fragmentShaderFilename[] = "../ressource/shaders/filled_arc.frag";
		isLoaded = shader.loadFromFile(vertexShaderFilename, geometryShaderFilename, fragmentShaderFilename);
	}
}

void Filled_arc::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	shader.setUniform("radius",int(radius));
	shader.setUniform("nbangles",int(nbangles));
	shader.setUniform("width",int(target.getSize().x));
	shader.setUniform("height",int(target.getSize().y));
	shader.setUniform("deg",float(deg));
	shader.setUniform("color",sf::Glsl::Vec4(point.color.r/255.0,point.color.g/255.0,point.color.b/255.0,point.color.a/255.0));
	states.shader = &shader;
	sf::VertexArray vertices(sf::Points,1);
	vertices[0] = point;
	target.draw(vertices, states);
}

void Filled_arc::setPosition(const sf::Vector2f& position){
	point.position = position;
}

void Filled_arc::setColor(const sf::Color& col) {
	point.color = col;
}

void Filled_arc::setRadius(const unsigned rad ){
	radius = rad;
}

void Filled_arc::setNBangles(const unsigned nba){
	nbangles = nba;
}

void Filled_arc::setDeg(const float& degre){
	deg = degre;
}