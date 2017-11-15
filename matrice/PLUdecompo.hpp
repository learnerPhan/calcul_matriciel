#ifndef PLUDECOMPO_H
#define PLUDECOMPO_H

#include "identityMatrice.hpp"
#include "vecteur.hpp"

// decomposition PLU.
// calcul 3 matrices P, L, U telles que PA = PLU
// revoie 0 if matrice has PLU decomposition; -1 sinon
class PLUdecompo
{
	public:
		PLUdecompo (const Matrice& A);
		inline Matrice getP() const {return P;} 
		inline Matrice getL() const {return L;} 
		inline Matrice getU() const {return U;}
		int decompoPLU();
		int resolPLU(const Vecteur& b, Vecteur& sol); 
	private:
		Matrice P;
		Matrice L;
		Matrice U;
		// echange des lignes
		void echange_lignes (Matrice& M, size_t l1, size_t l2);
	
		// cherche la ligne sous la diagonal contenant l'element
		// le plus grand en valeur absolue
		int max_ligne (const Matrice& M, size_t diag);

		// elimination dans la matrice U et met a jour L
		void elimination_ligne (Matrice& M, Matrice& N, size_t diag, size_t ligne);

};

#endif
