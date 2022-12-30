#include "TestProject.h"
#include <regex>
#include <string>
#include <iostream>

void RegexTest()
{
	std::string string{ "5sasd" };
	std::regex regex("\\d{1}\\w*");

	std::cout << string << " : " << std::boolalpha << std::regex_match(string, regex) << std::endl;
}

template<int A, int B>
struct GCD
{
	static const int result = GCD<B,A % B>::result;
};

template<int A>
struct GCD<A,0>
{
	static const int result = A;
};

void Metaprograming()
{
	int N = GCD<20, 4>::result;
}
