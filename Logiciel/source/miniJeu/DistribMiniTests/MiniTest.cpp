#include "../../../header/miniJeu/DistribMiniTests/MiniTest.h"

MiniTest::MiniTest() {

}

MiniTest::MiniTest(sf::Vector2f pos) {

	setPosition(pos);
	x = pos.x;
	y = pos.y;

	setSize(sf::Vector2f(40, 60));
	setFillColor(sf::Color::White);

	isThrown = false;

}

MiniTest::~MiniTest() {

}

void MiniTest::update() {
	if (isThrown) {

	}
}