#include "utils.hpp"

int main ()
{
	Base	*objPtr = generate();
	Base	&objRef = *objPtr;

	identify(objPtr);
	identify(objRef);

	delete objPtr;

	return (0);
}