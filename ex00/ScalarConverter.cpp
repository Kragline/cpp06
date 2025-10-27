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

static void	toChar(const std::string &literal)
{
	std::cout << static_cast<char>(literal[0]) << std::endl;
	exit(0);
}

static void	toInt(const std::string &literal)
{
	char	*endPtr;

	errno = 0;
	long	longResult = std::strtol(literal.c_str(), &endPtr, 10);

	if (*endPtr != '\0' || errno == ERANGE || longResult < INT_MIN || longResult > INT_MAX)
	{
		std::cerr << "Int convertation error" << std::endl;
		exit(1);
	}
	std::cout << static_cast<int>(longResult) << std::endl;
	exit(0);
}

void	ScalarConverter::convert(std::string literal)
{
	switch (TypeDetector::detectType(literal)) {
        case CHAR: toChar(literal); break;
        case INT: toInt(literal); break;
        case FLOAT: std::cout << "FLOAT"; break;
        case DOUBLE: std::cout << "DOUBLE"; break;
        case PSEUDO: std::cout << "PSEUDO"; break;
        case INVALID: std::cout << "INVALID"; break;
    }
    std::cout << std::endl;
}
