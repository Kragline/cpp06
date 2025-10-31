#pragma once

#include <iostream>
#include <cstdlib>
#include <cerrno>

#include "TypeDetector.hpp"
#include "Printer.hpp"

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
