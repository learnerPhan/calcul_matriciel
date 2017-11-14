#include "vecteur.hpp"

using namespace std;

Vecteur::Vecteur (size_t t_taille)
	:m_taille (t_taille)
{
	for (size_t i = 0; i < m_taille; ++i)
	{
		m_donnees.push_back(0.);
	}
}

Vecteur::Vecteur (const Vecteur& vect)
	:m_taille (vect.m_taille)
{
	for (size_t i = 0; i < m_taille; ++i)
	{
		m_donnees.push_back (vect.m_donnees[i]);
	}
}

ostream& operator<< (ostream& t_os, const Vecteur& vect)
{
	t_os << vect.m_taille << '\n';
	for (size_t i = 0; i < vect.m_taille; ++i)
	{
		t_os << vect.m_donnees[i] << "    ";
	}
	t_os << std::endl;
	return t_os;
}

Vecteur& Vecteur::operator+= (const Vecteur& vect)
{
	for (size_t i = 0; i < m_taille; ++i)
	{
		m_donnees[i] += vect.m_donnees[i];
	}
	return *this;
}

Vecteur& Vecteur::operator-= (const Vecteur& vect)
{
	for (size_t i = 0; i < m_taille; ++i)
	{
		m_donnees[i] -= vect.m_donnees[i];
	}
	return *this;
}
