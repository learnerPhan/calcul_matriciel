#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include <iostream>
#include <vector>

class Vecteur
{
	public:
		// constructeur vide
		Vecteur () {};
		
		// constructeur prenant un entier et cree un vecteur zero
		Vecteur (size_t t_taille);

		// constructeur recopie
		Vecteur (const Vecteur& vect);

		// renvoie la taille
		inline size_t getTaille() const {return m_taille;};

		// fonction affichage
		friend std::ostream& operator<< (std::ostream& t_os, const Vecteur& vect);
	
		// accesseur pour accéder et modifier un élément
		inline double& operator() (size_t i) {return m_donnees[i];};

		// accesseur pour lire un élément
		inline double operator() (size_t i) const {return m_donnees[i];};

		// operator += should be member
		// operator += returns its result per reference 
		Vecteur& operator+= (const Vecteur& vect);

		// operator + should be non-member
		// operator + returns its result by copy
		// operator + takes its left operand by copy
		friend inline Vecteur operator+ (Vecteur a, const Vecteur& b)
		{
			a += b;
			return a; 
		}

		Vecteur& operator-= (const Vecteur& vect);

		friend inline Vecteur operator- (Vecteur a, const Vecteur& b)
		{
			a -= b;
			return a;
		}
	private:
		size_t m_taille;
		std::vector <double> m_donnees;
};

#endif
