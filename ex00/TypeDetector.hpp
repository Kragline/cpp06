#pragma once

#include <cctype>
#include <iostream>
#include <cstdlib>
#include <limits>

enum Type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
};

class TypeDetector
{
private:
	TypeDetector();
	TypeDetector(const TypeDetector &other);
	~TypeDetector();
	TypeDetector	&operator=(const TypeDetector &other);
	
	static bool	_isChar(const std::string &literal);
	static bool	_isInt(const std::string &literal);
	static bool	_isFloat(const std::string &literal);
	static bool	_isDouble(const std::string &literal);
public:
	static Type	detectType(const std::string &literal);
};
