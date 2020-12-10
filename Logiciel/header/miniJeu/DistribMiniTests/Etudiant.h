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
	 * \param numEtu numéro de l'étudiant, permettant de déterminer sa position et sa texture correpondante.
	 */
	Etudiant(unsigned numEtu);
	virtual ~Etudiant();

	/**
	 * 
	 * \param pos position du mini test.
	 * \return true si l'étudiant peux attraper le mini test à la position pos, si il n'en a pas déjà un, false sinon
	 */
	bool tryToCatch(const sf::Vector2f& pos);

	/**
	 * Opérateur utilisé par sort pour trier les passants.
	 *
	 * \param e l'étudiant avec qui comparer
	 * \return true si la position verticale est inférieure a celle de e
	 */
	bool operator< (Etudiant& e)const;

private:

	static sf::Vector2f etuPos[6];

	bool working;

};

#endif