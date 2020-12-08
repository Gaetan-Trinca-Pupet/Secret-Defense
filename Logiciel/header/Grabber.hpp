#ifndef __GRABBER_HPP_
#define __GRABBER_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

#include <iostream>

namespace Grabber
{
	class Grabbable : public sf::RectangleShape
	{
	protected:
		
	public:
		Grabbable(const int& X = 0, const int& Y = 0, const int& sx = 0, const int& sy = 0);
		virtual ~Grabbable();

		virtual void updateOnGrab();
		virtual void onGrab();
		virtual void onRelease();

		virtual bool canBeGrabbed();

	};

	class Grabber
	{
	private:
		std::vector<Grabbable*> tabGrabbable;
		Grabbable* grabbed;

		sf::Sprite sprite;
		sf::Texture texture;

		int x;
		int y;

		int lastX;
		int lastY;

		int size_x;
		int size_y;

		bool isGrabbing;
		bool canGrab(Grabbable* const grab)const;

	public:
		Grabber();
		Grabber(std::vector<Grabbable*>& tab);

		~Grabber();

		void add( Grabbable* grab);
		void remove(const Grabbable* grab);

		void setSprite(const sf::Texture& textur);

		void update(sf::RenderWindow& window);
		void draw(sf::RenderWindow& window);

		void setX(const int& X);
		void setY(const int& Y);

		bool find(const Grabbable* grab) const;
	};



// Definition of Grabbable

	// Constructor of Grabbable++

	inline Grabbable::Grabbable(const int& X, const int& Y, const int& sx, const int& sy) 
	{
		setPosition(X, Y);
		setSize(sf::Vector2f(sx, sy));
	}

	// Detructor of Grabbable
	inline Grabbable::~Grabbable()
	{

	}

	// virtual function to update the object when it is grabbed.
	inline void Grabbable::updateOnGrab()
	{

	}

	// virtual function called when the object was just grabbed
	inline void Grabbable::onGrab()
	{

	}

	// virtual function called when the object was released
	inline void Grabbable::onRelease()
	{
		
	}

	inline bool Grabbable::canBeGrabbed()
	{
		return true;
	}


// Definition of Grabber

	// canGrab() is used to know if the cursor is hovering over an Grabbable parameter, if it is, it return true
	inline bool Grabber::canGrab(Grabbable* const grab)const
	{
		return grab->getGlobalBounds().contains(sf::Vector2f(x, y));
	}

	inline Grabber::Grabber()
	{
        lastX=0;
        lastY=0;
        x=0;
        y = 0;
		isGrabbing = false;
		grabbed = nullptr;
	}

	// Constructor of Grabber, it needs a vector of all the Item you can grab
	inline Grabber::Grabber(std::vector<Grabbable*>& tab)
	{
		tabGrabbable.resize(tab.size());
		for (unsigned i(0) ; i < tab.size() ; ++i)
			tabGrabbable[i] = tab[i];
        lastX=0;
        lastY=0;
        x=0;
        y = 0;
		isGrabbing = false;
		grabbed = nullptr;
	}

	// Destructor of Grabber
	inline Grabber::~Grabber()
	{
		delete grabbed;
        //for (unsigned i = 0; i < tabGrabbable.size(); ++i)
            //delete tabGrabbable[i];
	}

	inline void Grabber::add(Grabbable* grab)
	{
		if (!this->find(grab))
			tabGrabbable.push_back(grab);
	}


	inline void Grabber::remove(const Grabbable* grab)
	{
		if (this->find(grab))
			for(unsigned i (0) ; i < tabGrabbable.size() ; ++i)
				if (tabGrabbable[i] == grab)
				{
					tabGrabbable.erase(tabGrabbable.begin() + i);
					return;
				}
	}

	// Allows the user to set the sprite of the cursor, the size doesn't matter
	// The texture must be an image split in half, one half for when the user is left clicking, the other for when the user is not
	// For example, image.png (50x100) (WIDTHxHEIGHT) will be split in two 50x50 texture
	inline void Grabber::setSprite(const sf::Texture& textur)
	{
		texture = textur;
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
				for (unsigned i(0); i < tabGrabbable.size() && grabbed == nullptr; ++i)
					if (tabGrabbable[i]->canBeGrabbed() && canGrab(tabGrabbable[i]))
					{
						grabbed = tabGrabbable[i];
						grabbed->onGrab();
					}
			}

			if (grabbed != nullptr)
			{
				if (!grabbed->canBeGrabbed()) {
					grabbed->onRelease();
					grabbed = nullptr;
				}
				else {
					grabbed->move(x - lastX, y - lastY);
					grabbed->updateOnGrab();
				}
			}
		}
		else
		{
			if (grabbed != nullptr)
				grabbed->onRelease();

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

	// Set the x position of the cursor
	inline void Grabber::setX(const int& X)
	{
		x = X;
	}

	// Set the y position of the cursor
	inline void Grabber::setY(const int& Y)
	{
		y = Y;
	}

	inline bool Grabber::find(const Grabbable* grab) const
	{
		for (unsigned i(0); i < tabGrabbable.size() ; ++i)
			if (tabGrabbable[i] == grab)
				return true;
		return false;
	}
}

#endif
