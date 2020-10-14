#include "../header/Filled_arc.h"

sf::Shader EteindrePC::Filled_arc::shader;
bool EteindrePC::Filled_arc::isLoaded;

EteindrePC::Filled_arc::Filled_arc(const sf::Vector2f& position, const sf::Color& col, const unsigned int rad, const unsigned int nba)
		: point(position,col), radius(rad), nbangles(nba), deg(2*3.14159265358979323846){
	if(!isLoaded){
		constexpr char vertexShaderFilename[] = "../ressource/EteindrePC/shaders/filled_arc.vert";
		constexpr char geometryShaderFilename[] = "../ressource/EteindrePC/shaders/filled_arc.geom";
		constexpr char fragmentShaderFilename[] = "../ressource/EteindrePC/shaders/filled_arc.frag";
		isLoaded = shader.loadFromFile(vertexShaderFilename, geometryShaderFilename, fragmentShaderFilename);
	}
}

void EteindrePC::Filled_arc::draw(sf::RenderTarget& target, sf::RenderStates states) const{
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

void EteindrePC::Filled_arc::setPosition(const sf::Vector2f& position){
	point.position = position;
}

void EteindrePC::Filled_arc::setColor(const sf::Color& col){
	point.color = col;
}

void EteindrePC::Filled_arc::setRadius(const unsigned rad ){
	radius = rad;
}

void EteindrePC::Filled_arc::setNBangles(const unsigned nba){
	nbangles = nba;
}

void EteindrePC::Filled_arc::setDeg(const float& degre){
	deg = degre;
}