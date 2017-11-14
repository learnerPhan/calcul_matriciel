#ifndef IDENTITYMATRICE_HPP
#define IDENTITYMATRICE_HPP

#include "matrice.hpp"

class IdentityMatrice : public Matrice
{
	public:
		// constructeur vide
		IdentityMatrice () {};

		// constructeur prenant un entier comme la dimension de matrice	
		IdentityMatrice (std::size_t dim);


};

#endif


