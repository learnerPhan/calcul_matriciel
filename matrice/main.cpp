#include <iostream>
#include "matrice.hpp"
#include "vecteur.hpp"

using namespace std;

int main ()
{
	Matrice A(5);
	cout << A;

	for (size_t i = 0; i < A.getTaille(); ++i)
	{
		for (size_t j = 0; j < A.getTaille(); ++j)
		{
			A(i,j) = (double)(i*A.getTaille() + j);
		}
	}
	cout << A;

	Matrice B(5);
	Matrice C(5);
	for (size_t i = 0; i < A.getTaille(); ++i)
	{
		B(i,i) = (double)(i*A.getTaille() + i);
	}
	C = A + B;
	cout << A;
	cout << C;

	Vecteur v(5);
	cout << v;	

	for (size_t i = 0; i < v.getTaille(); ++i)
	{
		v(i) = (double) i;
	}
	cout << v;

	Vecteur w(v);
	Vecteur u(w + v);
	cout << u;

	u -= v;	
	cout << u;
	//u = v - w;
	//cout << u;

	Vecteur t;
	t = A * u;
	cout << A;
	cout << u;
	cout << t;

	Matrice M(3);
	M(0,0) = M(1,0) = M(2,0) = 1.;
	M(1,1) = M(2,1) = 2.;
	M(2,2) = 3.;
	Vecteur y(3);
	y(0) = 1;
	y(1) = 3;
	y(2) = 6;
	Vecteur x(3);
	x = inv_triang_inf (M,y);
	cout << M;
	cout << y;
	cout << x;
	Matrice N(3);
	N(0,0) = N(1,1) = N(2,2) = 1.;
	N(0,1) = N(1,2) = 2.;
	N(0,2) = 3.;
	y(0) = 6;
	y(1) = 3;
	y(2) = 1;
	x = inv_triang_sup (N,y);
	cout << N;
	cout << y;
	cout << x;
	return 0;
}
