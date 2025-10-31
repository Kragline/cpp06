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

// void	Printer::forFloat(float f)
// {

// }
