#include "utils.hpp"

Base	*generate()
{
	srand(static_cast<unsigned>(time(0)));
	int	randNbr = rand() % 3;

	if (randNbr == 0)
	{
		std::cout << "Object of type 'A' was generated" << std::endl;
		return (new A());
	}
	else if (randNbr == 1)
	{
		std::cout << "Object of type 'B' was generated" << std::endl;
		return (new B());
	}
	std::cout << "Object of type 'C' was generated" << std::endl;
	return (new C());
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "Object type pointed by Base *p is 'A'" << std::endl;
		return ;
	}
	if (dynamic_cast<B *>(p))
	{
		std::cout << "Object type pointed by Base *p is 'B'" << std::endl;
		return ;
	}
	if (dynamic_cast<C *>(p))
	{
		std::cout << "Object type pointed by Base *p is 'C'" << std::endl;
		return ;
	}
	std::cout << "Object type pointed by Base *p is unknown" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "Object type rederenced by Base &p is 'A'" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Object type rederenced by Base &p is 'B'" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Object type rederenced by Base &p is 'C'" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	std::cout << "Object type rederenced by Base &p is unknown" << std::endl;
}
