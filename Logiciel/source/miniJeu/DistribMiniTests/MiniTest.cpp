#include "../../../header/miniJeu/DistribMiniTests/MiniTest.h"

MiniTest::MiniTest()
{

}

MiniTest::MiniTest(sf::Vector2f pos, float rotation, sf::FloatRect _throwRange, sf::RenderWindow& _window)
{

	winSize = _window.getView().getSize();
	throwRange = _throwRange;

	setPosition(pos);
	setRotation(rotation);

	setSize(sf::Vector2f(65, 85));
	setOrigin(getSize().x / 2, getSize().y / 2);
	setFillColor(sf::Color::White);
	setOutlineThickness(3);
	setOutlineColor(sf::Color::Black);

	isThrown = false;
	throwSpeed = 2.5;

	setTexture(&AssetManager::getTexture("../ressource/DistribMiniTests/MiniTest.png"));
	rTex.create(getSize().y * 2, getSize().y * 2);
}

bool MiniTest::canBeGrabbed()
{
	return !isThrown;
}

void MiniTest::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Sprite sprite;
	sprite.setTexture(rTex.getTexture());
	sprite.setPosition(getPosition());
	sprite.setOrigin(getSize().y, getSize().y);

	if (isThrown)
		sprite.setScale(1, (1 - ((winSize.y - (getPosition().y > 100 ? getPosition().y : 100)) / winSize.y)));

	target.draw(sprite);

}

MiniTest::~MiniTest()
{

}

void MiniTest::update()
{

	if (isThrown)
	{

		move(throwDir);
		rotate(11);

		float scale = getScale().x;
		if (scale > 0)
		{
			float scaleDiff = scale - 0.003;
			setScale(scaleDiff, scaleDiff);
		}
	}
	else
	{

		if (!throwRange.contains(getPosition()))
		{
			isThrown = true;

			float hyp = sqrt(pow(getPosition().x - (lastPos.x), 2) + pow(getPosition().y - lastPos.y, 2));

			throwDir.x = (getPosition().x - (lastPos.x)) / hyp;
			throwDir.y = (getPosition().y - (lastPos.y)) / hyp;
			throwDir *= throwSpeed;

			setPosition(lastPos);
		}

		lastPos = getPosition();
	}


	rTex.clear(sf::Color::Transparent);
	sf::Vector2f pos(getPosition());
	setPosition(getSize().y, getSize().y);
	rTex.draw(sf::RectangleShape(*this));
	setPosition(pos);
	rTex.display();
}