#pragma once
#include <iostream>

class MyComplex {
private:
	float img, real;

public:
	MyComplex();
	MyComplex(float im, float re);
	MyComplex(const MyComplex&);

	void println();
	
	const MyComplex operator*(const MyComplex & mc) const;
	const MyComplex operator+(const MyComplex& mc) const;
	const MyComplex operator-(const MyComplex& mc) const;
	const MyComplex operator/(const MyComplex& mc) const;
	
	MyComplex& operator+=(MyComplex& mc);
	MyComplex& operator-=(MyComplex& mc);
	MyComplex& operator/=(MyComplex& mc);
	MyComplex& operator*=(MyComplex& mc);


};

MyComplex operator+(const MyComplex& Lef, const MyComplex& Righ);
