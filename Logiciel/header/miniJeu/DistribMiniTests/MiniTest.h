#ifndef __MINITEST_H_
#define __MINITEST_H_

#include "../../Grabber.hpp"

class MiniTest : public Grabber::Grabbable, public sf::RectangleShape {
public:


	MiniTest();
	virtual ~MiniTest();
	MiniTest(sf::Vector2f pos);

	void update();

private:

	bool isThrown;
	

};

#endif