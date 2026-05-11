#include <iostream>
#include <cstdlib>
#include <ctime>
#include "functions.hpp"
#include "ABC.hpp"

Base* generate(void)
{
	int r = std::rand() % 3;
	if (r == 0)
	{
		std::cout << "[Generate] Creatring A " << std::endl;
		return (new A());
	}
	else if (r == 1)
	{
		std::cout << "[Generate] Creating B " << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "[Generate] Creating C " << std::endl;
		return (new C());
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unkown" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch (std::exception&) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch (std::exception&) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}	catch (std::exception&) {}
	std::cout << "Unknown" << std::endl;
}