#include "MyComplex.h"

MyComplex::MyComplex(){}
MyComplex::MyComplex( float re, float im):img(im),real(re){}
MyComplex::MyComplex(const MyComplex& mc){
	img = mc.img;
	real = mc.real;
}


void MyComplex::println() {

	printf(" real = %f, img = %f\n", real, img);
}


const MyComplex MyComplex::operator+(const MyComplex& mc) const{
	MyComplex my_com(real + mc.real, img + mc.img);
	return my_com;
}
const MyComplex MyComplex::operator-(const MyComplex& mc) const{
	MyComplex my_com(real - mc.real, img - mc.img);
	return my_com;
}
const MyComplex MyComplex::operator*(const MyComplex & mc) const {
	MyComplex my_com(real * mc.real - img * mc.img
		, real * mc.img + mc.real * img);
	return my_com;
}
const MyComplex MyComplex::operator/(const MyComplex& mc) const{
	MyComplex my_com(
		(real * mc.real + img * mc.img)/ (mc.real * mc.real + mc.img * mc.img)
		, (mc.real * img - real * mc.img)/(mc.real * mc.real + mc.img * mc.img));
	return my_com;
}

MyComplex& MyComplex::operator+=(MyComplex& mc){
	(*this) = (*this).operator+(mc);
	return (*this);
}
MyComplex& MyComplex::operator-=(MyComplex& mc){
	(*this) = (*this) - mc;
	return (*this);
}
MyComplex& MyComplex::operator/=(MyComplex& mc){
	(*this) = (*this) / mc;
	return (*this);
}
MyComplex& MyComplex::operator*=(MyComplex& mc){
	(*this) = (*this) * mc;
	return (*this);
}

MyComplex operator+(const MyComplex& Lef, const MyComplex& Righ) {
	return Lef.operator+(Righ);
}
