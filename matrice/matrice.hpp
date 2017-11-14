#ifndef MATRICE_HPP
#define MATRICE_HPP

#include <iostream>
#include <vector>

// forward declaration (for operation *)
class Vecteur;

class Matrice
{
	public:
		// constructeur vide
		Matrice () {};

		// constructeur prenant un entier et crée une matrice carré
		// zéros
		Matrice (std::size_t t_taille); 

		// constructeur prenant un entier comme dimension et un vecteur
		Matrice (std::size_t t_taille, const std::vector<double>& t_donnees);

		// constructeur par recopie
		//Matrice (const Matrice& t_M);
		Matrice (const Matrice& t_M): m_taille(t_M.m_taille) {m_donnees = t_M.m_donnees;};

		// destructeur
		~Matrice() {};

		// fonction swap qui sert à operation assignement
		friend void swap (Matrice& lune, Matrice& lautre);

		// operation assignment
		inline Matrice& operator= (Matrice lautre)
		{
			swap (*this, lautre);
			return *this;
		}
		

		// méthode constante et inline qui renvoie la taille de la matrice
		inline std::size_t getTaille () const {return m_taille;};

		// méthode qui affiche la matrice 
		friend std::ostream& operator<< (std::ostream& t_os, const Matrice& t_M);

		// un accesseur non-constant qui peut accéder et modifier un coeff
		inline double& operator() (size_t ligne, size_t col) {return m_donnees[ligne*m_taille + col];};

		// un accesseur constant qui ne peut qu'accéder à un coeff
		inline double operator() (size_t ligne, size_t col) const {return m_donnees[ligne*m_taille + col];};

		// opération d'additon +=
		/* remarque sur C++ :
		 * operator += (changing their left argument)should be member
		 * operator += return its result par reference
		*/
		Matrice& operator+= (const Matrice& A); 
	 
		// opération d'addition
		/* remarque sur C++ :
		 * operator + should be non-member
		 * operator + takes its left operand by copy rather than by 
		 * const reference
		 * operator + returns a copy of its result
		*/
		friend inline Matrice operator+ (Matrice A, const Matrice& B)
		{
			A += B;
			return A;
		};

		// multiplication avec un vecteur
		friend Vecteur operator* (const Matrice& mat, const Vecteur& vect);

		// transposer la matrice
		Matrice& transposer();
	protected:
		std::size_t m_taille;
		std::vector<double> m_donnees;
};


#endif
