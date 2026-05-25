#include "Span.hpp"

int main(void)
{
	Span sp = Span(4);
	sp.addNumber(6);
	sp.addNumber(7);
	sp.addNumber(-1);
	sp.addNumber(10);

	std::cout << "===== Short && long =====" << std::endl;
	std::cout << "Shortest diff: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest diff: " << sp.longestSpan() << std::endl;

	std::cout << std::endl;
	std::cout << "==== Limit test ====" << std::endl;
	try
	{
		sp.addNumber(55);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "==== Few numbers ====" << std::endl;
	Span sp2(1);
	sp2.addNumber(5);
	try
	{
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << sp2.longestSpan() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "==== Empty test ==== " << std::endl;
	Span sp3(2);
	try
	{
		std::cout << sp3.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "==== Addrange with vector ====" << std::endl;
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(5);
	Span sp4(4);
	sp4.addRange(vec.begin(), vec.end());
	std::cout << "Shortest diff: " << sp4.shortestSpan() << std::endl;
	std::cout << "Longest: diff: " << sp4.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "=== Addrange with list ====" << std::endl;
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(100);
	lst.push_back(200);
	Span sp5(3);
	sp5.addRange(lst.begin(), lst.end());
	std::cout << "Shortest diff: " << sp5.shortestSpan() << std::endl;
	std::cout << "LongestTest diff: " << sp5.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "=== Large Scale Test ====" << std::endl;
	srand(42);
	Span bigSpan(10000);
	std::vector<int> Bigvec;
	for (int i = 0; i < 10000; i++)
		Bigvec.push_back(rand() % 1000000);
	bigSpan.addRange(Bigvec.begin(), Bigvec.end());
	std::cout << "Shortest diff: " << bigSpan.shortestSpan() << std::endl;
	std::cout << "Longest diff: " << bigSpan.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "=== Addrange overflow ===" << std::endl;
	Span sp6(3);
	try
	{
		sp6.addRange(Bigvec.begin(), Bigvec.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}