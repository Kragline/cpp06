#pragma once

#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cerrno>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	~ScalarConverter();
	ScalarConverter	&operator=(const ScalarConverter &other);
public:
	static void convert(std::string literal);
};
