#include "matrice.hpp"
#include "vecteur.hpp"

using namespace std;

// constructeur prenant un entier et initialise a matrice zero
Matrice::Matrice (size_t t_taille)
	: m_taille (t_taille)
{
	for (size_t i = 0; i < m_taille*m_taille; ++i)
	{
		m_donnees.push_back(0.);
	}
}

// constructeur prenant un vecteur
Matrice::Matrice (size_t t_taille, const vector<double>& t_donnees)
	: m_taille (t_taille)
{
	for (size_t i = 0; i < t_donnees.size(); ++i)
	{
		m_donnees.push_back(t_donnees[i]);
	}
}

// fonction swap
void swap (Matrice& lune, Matrice& lautre)
{
	using std::swap;
	swap (lune.m_taille, lautre.m_taille);
	swap (lune.m_donnees, lautre.m_donnees);
}

ostream& operator<< (ostream& t_os, const Matrice& t_M)
{
	t_os << t_M.m_taille << '\n';
	for (size_t i = 0; i < t_M.m_taille; ++i )
	{
		for (size_t j = 0; j < t_M.m_taille; ++j)
		{
			t_os << t_M.m_donnees[j + i*t_M.m_taille] << "    ";
		}
		t_os << "\n";
	}
	t_os << std::endl;
	return t_os;
}

Matrice& Matrice::operator+= (const Matrice& A)
{
	for (size_t i = 0; i < m_taille; ++i)
	{
		for (size_t j = 0; j < m_taille; ++j)
		{
			(*this)(i,j) += A(i,j);
		}
	}
	return *this;
}

Vecteur operator* (const Matrice& mat, const Vecteur& vect)
{
	Vecteur v(mat.m_taille);
	for (size_t i = 0; i < mat.m_taille; ++i)
	{
		for (size_t j = 0; j < mat.m_taille; ++j)
		{
			v(i) += mat(i,j)*vect(j);
		}
	}
	return v;
}

Matrice& Matrice::transposer()
{
	Matrice tmp(*this);
	for (size_t i = 0; i < m_taille; ++i)
	{
		for (size_t j = 0; j < m_taille; ++j)
		{
			(*this)(i,j) = tmp(j,i);
		}
	}
	return *this;
}
