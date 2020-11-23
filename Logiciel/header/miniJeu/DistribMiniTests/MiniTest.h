#ifndef __MINITEST_H_
#define __MINITEST_H_

#include "../../Grabber.hpp"

class MiniTest : public Grabber::Grabbable, public sf::RectangleShape {
public:
	bool isThrown;

private:
	MiniTest();
	MiniTest(sf::Vector2f pos);

	void update();

	virtual ~MiniTest();

};

#endif