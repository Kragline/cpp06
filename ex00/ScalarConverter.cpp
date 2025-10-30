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

// printing functions TODO

static void	handlePseudo(const std::string &literal)
{
	if (literal == "nanf")
	{
		std::cout << "NANF: " << std::numeric_limits<float>::quiet_NaN() << std::endl;
		exit(0);
	}
	if (literal == "+inff")
	{
		std::cout << "+INFF: " << std::numeric_limits<float>::infinity() << std::endl;
		exit(0);
	}
	if (literal == "-inff")
	{
		std::cout << "-INFF: " << -std::numeric_limits<float>::infinity() << std::endl;
		exit(0);
	}
	if (literal == "nan")
	{
		std::cout << "NAN: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
		exit(0);
	}
	if (literal == "+inf")
	{
		std::cout << "+INF: " << std::numeric_limits<double>::infinity() << std::endl;
		exit(0);
	}
	if (literal == "-inf")
	{
		std::cout << "-INF: " << -std::numeric_limits<double>::infinity() << std::endl;
		exit(0);
	}
}

static void	toChar(const std::string &literal)
{
	std::cout << "CHAR: " << static_cast<char>(literal[0]) << std::endl;
	exit(0);
}

static void	toInt(const std::string &literal)
{
	errno = 0;
	char	*endPtr;
	long	longResult = std::strtol(literal.c_str(), &endPtr, 10);

	if (endPtr == literal.c_str() || *endPtr != '\0')
	{
		std::cerr << "Error: Invalid integer format" << std::endl;
		exit(1);
	}
	if (errno == ERANGE || longResult < std::numeric_limits<int>::max()
		|| longResult > std::numeric_limits<int>::min())
	{
		std::cerr << "Error: Integer overflow" << std::endl;
		exit(1);
	}
	std::cout << "INT: " << static_cast<int>(longResult) << std::endl; //todo
	exit(0);
}

static void	toFloat(const std::string &literal)
{
	errno = 0;
	char		*endPtr;
	std::string	withoutF = literal.substr(0, literal.length() - 1);
	double		doubleValue = std::strtod(withoutF.c_str(), &endPtr);

	if (endPtr == withoutF.c_str() || *endPtr != '\0')
	{
		std::cerr << "Error: Invalid float format" << std::endl;
		exit(1);
	}
	if (errno == ERANGE || doubleValue < -std::numeric_limits<float>::min()
		|| doubleValue > std::numeric_limits<float>::max())
	{
		std::cerr << "Error: Float overflow" << std::endl;
		exit(1);
	}
	std::cout << "FLOAT: " << static_cast<float>(doubleValue) << std::endl;
	exit(0);
}

static bool	isZeroLiteral(const std::string &literal)
{
	return (literal == "0" || literal == "0.0" || literal == "+0" || 
			literal == "-0" || literal == "+0.0" || literal == "-0.0");
}

static void	toDouble(const std::string &literal)
{
	errno = 0;
	char		*endPtr;
	double		doubleValue = std::strtod(literal.c_str(), &endPtr);

	if (endPtr == literal.c_str() || *endPtr != '\0')
	{
		std::cerr << "Error: Invalid double format" << std::endl;
		exit(1);
	}
	if (errno == ERANGE || doubleValue < -std::numeric_limits<float>::min()
		|| doubleValue > std::numeric_limits<float>::max())
	{
		std::cerr << "Error: Double overflow" << std::endl;
		exit(1);
	}
	if (doubleValue == 0.0 && !isZeroLiteral(literal))
	{
		std::cerr << "Error: Invalid double format" << std::endl;
		exit(1);
	}
	std::cout << "DOUBLE: " << doubleValue << std::endl;
	exit(0);
}

void	ScalarConverter::convert(std::string literal)
{
	switch (TypeDetector::detectType(literal))
	{
		case CHAR: toChar(literal); break;
		case INT: toInt(literal); break;
		case FLOAT: toFloat(literal); break;
		case DOUBLE: toDouble(literal); break;
		case PSEUDO: handlePseudo(literal); break;
		case INVALID: std::cout << "Invalid literal format"; break;
	}
    std::cout << std::endl;
}
