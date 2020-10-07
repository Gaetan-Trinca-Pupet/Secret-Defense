#ifndef __GRABBER_H_
#define __GRABBER_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

namespace Grabber
{
	class Grabbed
	{
	protected:
		int x;
		int y;

		int size_x;
		int size_y;

		
	public:
		Grabbed(const int& X = 0, const int& Y = 0, const int& sx = 0, const int& sy = 0);
		virtual ~Grabbed();

		virtual void update()=0;

		void setX(const int& X);
		void setY(const int& Y);

		void setSizeX(const int& X);
		void setSizeY(const int& Y);

		void moveX(const int& X);
		void moveY(const int& Y);

		int getX()const;
		int getY()const;

		int getSizeX()const;
		int getSizeY()const;

	};

	class Grabber
	{
	private:
		std::vector<Grabbed*>* tabGrabbed;
		Grabbed* grabbed;

		sf::Sprite sprite;
		sf::Texture texture;

		int x;
		int y;

		int lastX;
		int lastY;

		int size_x;
		int size_y;

		bool isGrabbing;
		bool canGrab(Grabbed* const grab)const;

	public:
		Grabber(std::vector<Grabbed*>& tab);
		~Grabber();

		void setSprite(const std::string& str);

		void update(sf::RenderWindow& window);
		void draw(sf::RenderWindow& window);
	};



// Definition of Grabbed


	// Constructor of Grabbed
	inline Grabbed::Grabbed(const int& X, const int& Y, const int& sx, const int& sy) : x(X), y(Y), size_x(sx), size_y(sy)
	{

	}

	// Detructor of Grabbed
	inline Grabbed::~Grabbed()
	{

	}

	// virtual function to update the object.
	inline void update()
	{

	}

	// set the position on the x-axis of the object
	inline void Grabbed::setX(const int& X)
	{
		x = X;
	}

	// set the position on the y-axis of the object
	inline void Grabbed::setY(const int& Y)
	{
		y = Y;
	}

	// set the size on the x-axis of the object
	inline void Grabbed::setSizeX(const int& X)
	{
		size_x = X;
	}

	// set the size on the x-axis of the object
	inline void Grabbed::setSizeY(const int& Y)
	{
		size_y = Y;
	}

	// Move the object on the x-axis
	inline void Grabbed::moveX(const int& X)
	{
		x += X;
	}

	// Move the object on the y-axis
	inline void Grabbed::moveY(const int& Y)
	{
		y += Y;
	}

	// Return the position x of the object
	inline int Grabbed::getX()const
	{
		return x;
	}

	// Return the position y of the object
	inline int Grabbed::getY()const
	{
		return y;
	}

	// Return the size_x of the object
	inline int Grabbed::getSizeX()const
	{
		return size_x;
	}

	// Return the size_y of the object
	inline int Grabbed::getSizeY()const
	{
		return size_y;
	}

// Definition of Grabber

	// canGrab() is used to know if the cursor is hovering over an Grabbed parameter, if it is, it return true
	inline bool Grabber::canGrab(Grabbed* const grab)const
	{
		return 
			(((x >= grab->getX() - grab->getSizeX() / 2) && (x <= grab->getX() + grab->getSizeX() / 2)) ||
			((grab->getX() >= x - size_x / 2) && (grab->getX() <= x + size_x / 2))) &&
			(((y >= grab->getY() - grab->getSizeY() / 2) && (y <= grab->getY() + grab->getSizeY() / 2)) ||
			((grab->getY() >= y - size_y / 2) && (grab->getY() <= y + size_y / 2)));
	}

	// Constructor of Grabber, it needs a vector of all the Item you can grab
	inline Grabber::Grabber(std::vector<Grabbed*>& tab) : tabGrabbed(&tab)
	{
		lastX, lastY, x, y = 0;
		isGrabbing = false;
		grabbed = nullptr;

		setSprite("../ressource/BranchePC/open_hand.png");
	}

	// Destructor of Grabber
	inline Grabber::~Grabber()
	{
		delete grabbed;
		delete tabGrabbed;
	}

	// Allows the user to set the sprite of the cursor, the size doesn't matter
	// The texture must be an image split in half, one half for when the user is left clicking, the other for when the user is not
	// For example, image.png (50x100) (WIDTHxHEIGHT) will be split in two 50x50 texture
	inline void Grabber::setSprite(const std::string& str)
	{
		texture.loadFromFile(str);
		sprite.setTexture(texture);

		size_x = texture.getSize().x / 2;
		size_y = texture.getSize().y;
	}

	// Updates the cursor position (refferring to 'window') and what it is grabbing is left_cliking
	inline void Grabber::update(sf::RenderWindow& window)
	{
		x = sf::Mouse::getPosition(window).x;
		y = sf::Mouse::getPosition(window).y;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			if (!isGrabbing)
			{
				isGrabbing = true;
				for (unsigned i(0); i < tabGrabbed->size() && grabbed == nullptr; ++i)
					if (canGrab((*tabGrabbed)[i]))
						grabbed = (*tabGrabbed)[i];
			}

			if (grabbed != nullptr)
			{
				grabbed->moveX(x - lastX);
				grabbed->moveY(y - lastY);
				grabbed->update();
			}
		}
		else
		{
			grabbed = nullptr;
			isGrabbing = false;
		}
		lastX = x;
		lastY = y;
	}

	// Draws the cursor on 'window'
	inline void Grabber::draw(sf::RenderWindow& window)
	{
		sprite.setPosition(x - size_x / 2, y - size_y / 2);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			sprite.setTextureRect(sf::IntRect(size_x, 0, size_x, size_y));
		else
			sprite.setTextureRect(sf::IntRect(0, 0, size_x, size_y));

		window.draw(sprite);
	}
}

#endif