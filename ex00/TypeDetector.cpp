#include "TypeDetector.hpp"

// not implemented
TypeDetector::TypeDetector() {}

TypeDetector::TypeDetector(const TypeDetector &other) {	(void)other; }

TypeDetector::~TypeDetector() {}

TypeDetector	&TypeDetector::operator=(const TypeDetector &other) { (void)other; return (*this); }
//

bool	TypeDetector::_isChar(const std::string &literal)
{
	return (literal.length() == 1 && !std::isdigit(literal[0])); // removed is printable check
}

bool	TypeDetector::_isInt(const std::string &literal)
{
	size_t	i = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;
	
	if (literal[i] == '\0')
		return (false);
	
	for (; i < literal.length(); i++)
		if (!std::isdigit(literal[i]))
			return (false);

	return (true);
}

bool	TypeDetector::_isFloat(const std::string &literal)
{
	int	fCount = 0;
	
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (true);
	if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
		return (false);

	for (size_t i = 0; i < literal.length(); i++)
	{
		if (literal[i] == 'f')
		{
			fCount++;
			if (fCount > 1)
				return (false);
		}
	}

	std::string	withoutF = literal.substr(0, literal.length() - 1);
	return (_isDouble(withoutF));
}

bool	TypeDetector::_isDouble(const std::string &literal)
{
	bool	hasDot = false;
	bool	hasDigit = false;
	size_t	i = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;

	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return (true);

	if (literal[i] == '\0')
		return (false);

	for (; i < literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (hasDot) return (false);
			hasDot = true;
		}
		else if (std::isdigit(literal[i]))
			hasDigit = true;
		else
			return (false);
	}

	return (hasDigit && hasDot);
}

Type	TypeDetector::detectType(const std::string &literal)
{
	if (literal.empty()) return (INVALID);

	if (_isChar(literal)) return (CHAR);
	if (_isInt(literal)) return (INT);
	if (_isFloat(literal)) return (FLOAT);
	if (_isDouble(literal)) return (DOUBLE);

	return (INVALID);
}
