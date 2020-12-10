#ifndef __PASSANT_H_
#define __PASSANT_H_

#include "../../clickable.h"
#include "../../AssetManager.h"

class Passant : public Clickable
{

public:

	/**
	 * Constructeur de Passant.
	 * 
	 * \param pos position initiale
	 * \param window fenêtre (utilisée pour savoir si le passant a atteint l'autre côté de l'écran)
	 * \param dir direction vers laquelle el passant se déplace (1 vers la doite, -1 vers la gauche)
	 * \param isMasque indique sur le passant est masqué ou non
	 * \param difficulty difficulté, utilisée pour calculer la vitesse de déplacement
	 */
	Passant(const sf::Vector2f& pos, sf::RenderWindow* window, float dir, bool isMasque, unsigned difficulty);
	virtual ~Passant();

	/**
	 * Met a jour le passant.
	 * 
	 */
	void update();

	/**
	 * Indique si le passant a atteint l'autre côté de la fenêtre.
	 * 
	 * \return true si c'est la cas, false sinon
	 */
	bool isOutOfBounds();

	/**
	 * Indique si l'individu est masqué.
	 * 
	 * \return masked
	 */
	bool isMasked();

	/**
	 * Indique si l'individu a été giflé.
	 * 
	 * \return gifle
	 */
	bool isGifle();

	/**
	 * Opérateur utilisé par sort pour trier les passants.
	 * 
	 * \param p2 le passant avec qui comparer
	 * \return true si la position verticale est inférieure a celle de p2
	 */
	bool operator < (Passant& p2);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Sprite sprite;

	bool gifle;
	virtual void actionOnClick();
	float speed;
	float dir;
	bool masked;
	bool enFuite;
	sf::RenderWindow* window;

	sf::Clock clockPourDelaiFuite;

	sf::Clock clockPourDelaiAnimation;
};


#endif