#ifndef __PASSANT_H_
#define __PASSANT_H_

#include "../../clickable.h"
#include "../../miniJeu/MiniJeu.h"
#include "../../AssetManager.h"

class Passant : public Clickable
{

public:

	/**
	 * Constructeur de Passant.
	 * 
	 * \param pos position initiale
	 * \param window fen�tre (utilis�e pour savoir si le passant a atteint l'autre c�t� de l'�cran)
	 * \param dir direction vers laquelle el passant se d�place (1 vers la doite, -1 vers la gauche)
	 * \param isMasque indique sur le passant est masqu� ou non
	 * \param app sert � r�cup�rer la difficult� et pseudo
	 */
	Passant(const sf::Vector2f& pos, sf::RenderWindow* window, float dir, bool isMasque, AppData* app);
	virtual ~Passant();

	/**
	 * Met a jour le passant.
	 * 
	 */
	void update();

	/**
	 * Indique si le passant a atteint l'autre c�t� de la fen�tre.
	 * 
	 * \return true si c'est la cas, false sinon
	 */
	bool isOutOfBounds();

	/**
	 * Indique si l'individu est masqu�.
	 * 
	 * \return masked
	 */
	bool isMasked();

	/**
	 * Indique si l'individu a �t� gifl�.
	 * 
	 * \return trouve
	 */
	bool isTrouve();

	/**
	 * Op�rateur utilis� par sort pour trier les passants.
	 * 
	 * \param p2 le passant avec qui comparer
	 * \return true si la position verticale est inf�rieure a celle de p2
	 */
	bool operator < (Passant& p2);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	AppData* app;

	sf::Sprite sprite;

	bool trouve;
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