#ifndef IDENTITYMATRICE_H
#define IDENTITYMATRICE_H

#include "matrice.hpp"

class Vecteur;
class IdentityMatrice : public Matrice
{
	public:
		// constructeur vide
		IdentityMatrice () {};

		// constructeur prenant un entier comme la dimension de matrice	
		IdentityMatrice (std::size_t dim);


};

#endif


