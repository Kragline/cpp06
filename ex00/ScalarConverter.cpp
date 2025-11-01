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

static void	toInt(const std::string &literal)
{
	errno = 0;
	char	*endPtr;
	long	longResult = std::strtol(literal.c_str(), &endPtr, 10);

	if (endPtr == literal.c_str() || *endPtr != '\0'
		|| (longResult == 0 && literal != "0"))
	{
		std::cerr << "Error: Invalid integer format" << std::endl;
		exit(1);
	}
	if (errno == ERANGE || longResult < std::numeric_limits<int>::min()
		|| longResult > std::numeric_limits<int>::max())
	{
		std::cerr << "Error: Integer overflow" << std::endl;
		exit(1);
	}
	Printer::forInt(static_cast<int>(longResult));
}

static void	toFloat(const std::string &literal)
{
	if (literal == "nanf")
	{
		Printer::forFloat(std::numeric_limits<float>::quiet_NaN());
		return ;
	}
	else if (literal == "+inff")
	{
		Printer::forFloat(std::numeric_limits<float>::infinity());
		return ;
	}
	else if (literal == "-inff")
	{
		Printer::forFloat(-std::numeric_limits<float>::infinity());
		return ;
	}

	errno = 0;
	char		*endPtr;
	std::string	withoutF = literal.substr(0, literal.length() - 1);
	double		doubleValue = std::strtod(withoutF.c_str(), &endPtr);

	if (endPtr == withoutF.c_str() || *endPtr != '\0'
		|| (doubleValue == 0.0 && literal != "0.0f"))
	{
		std::cerr << "Error: Invalid float format" << std::endl;
		exit(1);
	}
	if (errno == ERANGE || doubleValue < -std::numeric_limits<float>::max()
		|| doubleValue > std::numeric_limits<float>::max())
	{
		std::cerr << "Error: Float overflow" << std::endl;
		exit(1);
	}
	Printer::forFloat(static_cast<float>(doubleValue));
}

static void	toDouble(const std::string &literal)
{
	if (literal == "nan")
	{
		Printer::forDouble(std::numeric_limits<double>::quiet_NaN());
		return ;
	}
	else if (literal == "+inf")
	{
		Printer::forDouble(std::numeric_limits<double>::infinity());
		return ;
	}
	else if (literal == "-inf")
	{
		Printer::forDouble(-std::numeric_limits<double>::infinity());
		return ;
	}

	errno = 0;
	char		*endPtr;
	double		doubleValue = std::strtod(literal.c_str(), &endPtr);

	if (endPtr == literal.c_str() || *endPtr != '\0'
		|| (doubleValue == 0.0 && literal != "0.0"))
	{
		std::cerr << "Error: Invalid double format" << std::endl;
		exit(1);
	}
	if (errno == ERANGE || doubleValue < -std::numeric_limits<double>::max()
		|| doubleValue > std::numeric_limits<double>::max())
	{
		std::cerr << "Error: Double overflow" << std::endl;
		exit(1);
	}
	Printer::forDouble(doubleValue);
}

void	ScalarConverter::convert(std::string literal)
{
	switch (TypeDetector::detectType(literal))
	{
		case CHAR: Printer::forChar(static_cast<char>(literal[0])); break;
		case INT: toInt(literal); break;
		case FLOAT: toFloat(literal); break;
		case DOUBLE: toDouble(literal); break;
		case INVALID: std::cerr << "Invalid literal format" << std::endl; break;
	}
}
