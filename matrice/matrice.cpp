#include "matrice.hpp"

using namespace std;

Matrice::Matrice (size_t t_taille)
{
	m_taille = t_taille;
	for (size_t i = 0; i < m_taille*m_taille; ++i)
	{
		m_donnees.push_back(0.);
	}
}

// constructeur par recopie
Matrice::Matrice (const Matrice& t_M)
{
	m_taille = t_M.m_taille;
	for (size_t i = 0; i < t_M.m_taille*t_M.m_taille; ++i)
	{
		m_donnees.push_back(t_M.m_donnees[i]);
	}
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
/* paramètres:
* M : matrice triangulaire inférieur
* y : vecteur
* renvoie : inv(M)*y
* Pour cela, il suffit de résoudre M*x = y, on obtenira x = inv(M)*y
*/
Vecteur inv_triang_inf (const Matrice& M, const Vecteur& y)
{
	Vecteur x(y.getTaille());
	double tmp = 0.;
	for (size_t i = 0; i < M.getTaille(); ++i)
	{
		x(i) = (y(i) - tmp)/M(i,i);
		tmp = 0.;
		for (size_t j = 0; j < i+1; ++j)
		{
			tmp += M(i+1,j)*x(j);
		} 
	}
	return x;
}

/* paramètres:
* M : matrice triangulaire supérieur
* y : vecteur
* renvoie : inv(M)*y
* Pour cela, il suffit de résoudre M*x = y, on obtenira x = inv(M)*y
*/
Vecteur inv_triang_sup (const Matrice& M, const Vecteur& y)
{
	Vecteur x(y.getTaille());
	double tmp = 0.;
	for (size_t i = y.getTaille() - 1; (int)i > -1; --i)
	{
		x(i) = (y(i) - tmp)/M(i,i);
		tmp = 0.;
		for (size_t j = y.getTaille() - 1; j > i-1; --j)
		{
			tmp += M(i-1,j)*x(j);
		} 
	}
	return x;

}
