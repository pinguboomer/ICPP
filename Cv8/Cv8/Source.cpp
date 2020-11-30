#include "Matice.h"
#include <iostream>


int main()
{
	Matrix<int> m{ 3,3 };
	int jednodpole[] = { 0,1,2,3,4,5,6,7,8 };
	m.setFrom(jednodpole);
	m.print();
	Matrix<int> mt = m.trans();
	mt.print();
	Matrix<int> mmt = m.multiplication(mt);
	mmt.print();
	Matrix<double> mmt_d = mmt.retype<double>();
	mmt_d.print();
	Matrix<double> n_d{ 3,3 };
	double jednodpole_d[] = { 4.5,5,0,2,-0.5,7,1.5,9,6 };
	n_d.setFrom(jednodpole_d);
	n_d.print();
	Matrix<double> mmtn_d = mmt_d.multiplication(n_d);
	Matrix<int> r = mmtn_d.retype<int>();
	r.print();
	Matrix<int> t{ 3,3 };
	int tpole[] = { 85,225,236,292,819,866,499,1413,1496 };
	t.setFrom(tpole);
	t.print();
	std::cout << "r==t ? " << (r.isSame(t) ? "true" : "false") << std::endl;
	return 0;
}