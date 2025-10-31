#include "Printer.hpp"

// not implemented
Printer::Printer() {}

Printer::Printer(const Printer &other)
{
	(void)other;
}

Printer::~Printer() {}

Printer	&Printer::operator=(const Printer &other)
{
	(void)other;
	return (*this);
}
//

void	Printer::forChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	Printer::forInt(int i)
{
	std::cout << "char: ";
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
		std::cout << "impossible";
	else if (!std::isprint(static_cast<char>(i)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(i) << "'";
	std::cout << std::endl;

	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void	Printer::forFloat(float f)
{
	std::cout << "char: ";
	if (std::isnan(f) || std::isinf(f) || f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
		std::cout << "impossible";
	else if (!std::isprint(static_cast<char>(f)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(f) << "'";
	std::cout << std::endl;

	std::cout << "int: ";
	if (std::isnan(f) || std::isinf(f) || f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(f);
	std::cout << std::endl;

	std::cout << "float: ";
	if (std::isnan(f))
		std::cout << "nanf";
	else if (f == std::numeric_limits<float>::infinity())
		std::cout << "inff";
	else if (f == -std::numeric_limits<float>::infinity())
		std::cout << "-inff";
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f";
	std::cout << std::endl;

	std::cout << "double: ";
	if (std::isnan(f))
		std::cout << "nan";
	else if (f == std::numeric_limits<float>::infinity())
		std::cout << "inf";
	else if (f == -std::numeric_limits<float>::infinity())
		std::cout << "-inf";
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(f);
	std::cout << std::endl;
}

void	Printer::forDouble(double d)
{
	std::cout << "char: ";
	if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
		std::cout << "impossible";
	else if (!std::isprint(static_cast<char>(d)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(d) << "'";
	std::cout << std::endl;

	std::cout << "int: ";
	if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(d);
	std::cout << std::endl;

	std::cout << "float: ";
	if (std::isnan(d))
		std::cout << "nanf";
	else if (d == std::numeric_limits<double>::infinity())
		std::cout << "inff";
	else if (d == -std::numeric_limits<double>::infinity())
		std::cout << "-inff";
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f";
	std::cout << std::endl;

	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan";
	else if (d == std::numeric_limits<double>::infinity())
		std::cout << "inf";
	else if (d == -std::numeric_limits<double>::infinity())
		std::cout << "-inf";
	else
		std::cout << std::fixed << std::setprecision(1) << d;
	std::cout << std::endl;
}
