#include "PLUdecompo.hpp"

#define ABS(x) (x > 0 ? x : -x)

PLUdecompo::PLUdecompo (const Matrice& A)
	: P(A.getTaille()), L(A.getTaille()), U(A)
{
	// initialiser P = Matrice identité
	for (size_t i = 0; i < A.getTaille(); ++i)
	{
		P(i,i) = 1.;
	}
	
}

void PLUdecompo::echange_lignes (Matrice& M, size_t l1, size_t l2)
{
	double tmp;
	for (size_t i = 0; i < M.getTaille(); ++i)
	{
		tmp = M(l1, i);
		M(l1, i) = M(l2, i);
		M(l2, i) = tmp;
	}
}

/* INPUT : une matrice, une indice
* OUTPUT : la ligne contenant l'element la plus grand en valeur absolue
*/
int PLUdecompo::max_ligne (const Matrice& M, size_t diag)
{
	size_t tmp = diag;
	double max = ABS(M(diag,diag));
	for (size_t i = 1; i < M.getTaille() - diag; ++i)
	{
		if (ABS(M(diag+i, diag)) > max)
		{
			tmp = diag + i;
			max = ABS(M(diag+i, diag));
		}
	}
	if (max == 0.)
	{
		return -1;
	}
	return tmp;	
}

// fonction qui met à jour L et U en creeant des zeros au-dessus la diagonal dans U
void PLUdecompo::elimination_ligne (Matrice& M, Matrice& N, size_t diag, size_t ligne)
{
	N(ligne, diag) = M(ligne, diag)/M(diag, diag);
	for (size_t i = 0; i < U.getTaille(); ++i)
	{
		M(ligne, i) -= N(ligne, diag) * M(diag, i); 
	}
}
	

// le core de PLU decomposition
int PLUdecompo::decompoPLU()
{
	int maxligne;
	for (size_t i = 0; i < U.getTaille(); ++i)
	{
		// chercher l'élement le plus grand en valeur absolue dans a colonne		
		if ((maxligne = max_ligne (U,i) ) == -1)
		{
			return -1;
		}
		
		// swap des lignes
		if ((size_t)maxligne != i)
		{
			echange_lignes (P, i, maxligne);
			echange_lignes (U, i, maxligne);
			echange_lignes (L, i, maxligne);
		}

		// elimination des lignes au-dessous de la diagonal
		for (size_t j = i + 1; j < U.getTaille(); ++j)
		{
			elimination_ligne (U, L, i, j);
		}
	
	}
	// L = L + Id
	for (size_t i = 0; i < U.getTaille(); ++i)
	{
		L(i,i) += 1.;
	} 
	 		
	// P = tranposer P
	P.transposer();
	return 0;	
}

#undef ABS
