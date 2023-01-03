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

void STL::CuriosityVectorAddres()
{
	std::vector<int> V = {1,2,3,4,5};

	std::cout << &V.at(0) << " : " << &V.at(1) << std::endl;
}
