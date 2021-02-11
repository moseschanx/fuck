#include <iostream>

class Vector {

public:
	Vector(int s) : elem{ new double[s] }, sz{ s } {}
	~Vector() { delete[] elem; }

private:
	double* elem;
	int sz;
};

Vector* f(int s)
{
	Vector v1(s);
	return new Vector(s + s);
}