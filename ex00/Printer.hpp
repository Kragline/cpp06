#pragma once

#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>
#include <cfloat>

class Printer
{
private:
	Printer();
	Printer(const Printer &other);
	~Printer();
	Printer	&operator=(const Printer &other);
public:
	static void	forChar(char c);
	static void	forInt(int i);
	static void	forFloat(float f);
	static void	forDouble(double d);
};
