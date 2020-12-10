#ifndef __ETUDIANT_H_
#define __ETUDIANT_H_


#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>
#include "../../AssetManager.h"

class Etudiant : public sf::RectangleShape
{
public:

	Etudiant();

	/**
	 * Constructeur d'Etudiant.
	 * 
	 * \param numEtu num�ro de l'�tudiant, permettant de d�terminer sa position et sa texture correpondante.
	 */
	Etudiant(unsigned numEtu);
	virtual ~Etudiant();

	/**
	 * 
	 * \param pos position du mini test.
	 * \return true si l'�tudiant peux attraper le mini test � la position pos, si il n'en a pas d�j� un, false sinon
	 */
	bool tryToCatch(const sf::Vector2f& pos);

	/**
	 * Op�rateur utilis� par sort pour trier les passants.
	 *
	 * \param e l'�tudiant avec qui comparer
	 * \return true si la position verticale est inf�rieure a celle de e
	 */
	bool operator< (Etudiant& e)const;

private:

	static sf::Vector2f etuPos[6];

	bool working;

};

#endif