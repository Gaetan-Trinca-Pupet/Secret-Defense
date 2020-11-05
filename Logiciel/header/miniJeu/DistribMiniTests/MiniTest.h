#ifndef __MINITEST_H_
#define __MINITEST_H_

#include "../../Grabber.hpp"
#include "../../entity.h"

class MiniTest : public MiniJeu, public Entity{
public:

	virtual void update();

private:
	MiniTest();
	virtual ~MiniTest();

};

#endif