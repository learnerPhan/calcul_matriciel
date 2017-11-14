#include <iostream>
#include "PLUdecompo.hpp"
#include "matrice.hpp"
using namespace std;

int main ()
{
	Matrice A(5);

	for (size_t i = 0; i < A.getTaille(); ++i)
	{
		for (size_t j = 0; j < A.getTaille(); ++j)
		{
			A(i,j) = (double)(i*A.getTaille() + j);
		}
	}

	Matrice B(5);
	Matrice C(5);
	for (size_t i = 0; i < A.getTaille(); ++i)
	{
		B(i,i) = (double)(i*A.getTaille() + i);
	}
	C = A + B;

	Vecteur v(5);

	for (size_t i = 0; i < v.getTaille(); ++i)
	{
		v(i) = (double) i;
	}

	Vecteur w(v);
	Vecteur u(w + v);

	u -= v;	
	//u = v - w;
	//cout << u;

	Vecteur t;
	t = A * u;

	Matrice M(3);
	M(0,0) = M(1,0) = M(2,0) = 1.;
	M(1,1) = M(2,1) = 2.;
	M(2,2) = 3.;
	Vecteur y(3);
	y(0) = 1;
	y(1) = 3;
	y(2) = 6;
	//Vecteur x(3);
	//sol_triang_inf (M, x, y);
	Matrice N(3);
	N(0,0) = N(1,1) = N(2,2) = 1.;
	N(0,1) = N(1,2) = 2.;
	N(0,2) = 3.;
	y(0) = 6;
	y(1) = 3;
	y(2) = 1;
	Vecteur x(3);
	sol_triang_sup (N, x, y);
	cout << N;
	cout << y;
	cout << x;

	vector<double> n = {1., 2., 3., 4.};
	Matrice P(2, n);

	Matrice Q(N);

	Q = M;

	IdentityMatrice I(5);

	//Matrice X (3, {1., 0., 4., 0., 0., 1., 3., 2., 13.});
	Matrice X (3, {2., 6., 12., 1., 3., 8., 4., 4., 8.});
	Vecteur h(3);
	h(0) = 28;
	h(1) = 18;
	h(2) = 16;
	PLUdecompo testplu(X);
	//testplu.decompoPLU();	
	testplu.resolPLU(h,x);	
	Matrice Y(3);
	Matrice J(3);
	Matrice K(3);
	Y = testplu.getP();
	J = testplu.getL();
	K = testplu.getU();
	cout << X;
	cout << Y;
	cout << J;
	cout << K;
	cout << x;
	return 0;
}
