#include "ScalarConverter.hpp"

// not implemented
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}
//

void	ScalarConverter::convert(std::string literal)
{
	switch (TypeDetector::detectType(literal)) {
        case CHAR: std::cout << "CHAR"; break;
        case INT: std::cout << "INT"; break;
        case FLOAT: std::cout << "FLOAT"; break;
        case DOUBLE: std::cout << "DOUBLE"; break;
        case PSEUDO: std::cout << "PSEUDO"; break;
        case INVALID: std::cout << "INVALID"; break;
    }
    std::cout << std::endl;
}
