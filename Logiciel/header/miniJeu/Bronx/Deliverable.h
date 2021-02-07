#include "../../Grabber.hpp"

class Deliverable : public Grabber::Grabbable
{
public:

	int groundLevel;
	bool stored;
	sf::RectangleShape* deliverZone;

	Deliverable(const int& X, const int& Y, const int& sx, const int& sy, bool _stored = false);

	void setTarget(sf::RectangleShape* zone);

	virtual void onRelease();

	virtual void onGrab();

	virtual void update();

	void setStored(bool val);

	bool isStored();

private:

	

};