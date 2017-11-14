#include "identityMatrice.hpp"

using namespace std;
// constructeur prenant un entier comme la dimension de la matrice
IdentityMatrice::IdentityMatrice (size_t dim)
	: Matrice(dim)
{
	for (size_t i = 0; i < dim; ++i)
	{
		m_donnees[i + i*dim] = 1.;	
	}
	
}
