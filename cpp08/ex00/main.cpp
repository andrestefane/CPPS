#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyFind.hpp"

template <typename T>
void testFind(T &container, int value, const std::string &containerName)
{
	std::cout << "[" << containerName << "] Searching for " << value << ": ";
	try
	{
		typename T::iterator it = easyfind(container, value);
		std::cout << "Found -> " << *it << std::endl;
	} 
	catch (const std::exception &e)
	{
		std::cout << "Exception -> " << e.what() << std::endl;
	}
}
int main(void)
{
	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(-1);
	std::cout << "===== VECTOR =====" << std::endl;

	testFind(vec, -1, "vector");
	testFind(vec, 3, "vector");
	testFind(vec, 100, "vector");
	std::cout << std::endl;

	std::list<int> lst;

	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_front(1);
	std::list<int>::iterator it;
	it = lst.begin();
	while (it != lst.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "===== LIST =====" << std::endl;
	testFind(lst, 1, "list");
	testFind(lst, -1, "list");
	testFind(lst, 100, "list");
	std::cout << std::endl;

	std::deque<int> deq;
	deq.push_back(10);
	deq.push_back(20);
	deq.push_back(30);
	deq.push_front(1);
	deq.push_front(0);
	std::deque<int>::iterator deqIT;
	deqIT = deq.begin();
	while (deqIT != deq.end())
	{
		std::cout << *deqIT << std::endl;
		deqIT++;
	}
	deq.pop_front(); // Erase 0
	deq.pop_back(); // Erase 30
	std::cout << "===== DEQUE =====" << std::endl;
	testFind(deq, 0, "deque");
	testFind(deq, 1, "deque");
	testFind(deq, 30, "deque");
	std::cout << std::endl;

	std::vector<int> empty;
	testFind(empty, 0, "empty");

	std::cout << std::endl;
    std::vector<int> dups;
    dups.push_back(5);
    dups.push_back(5);
    dups.push_back(5);
    typename std::vector<int>::iterator itvec = easyfind(dups, 5);
    std::cout << "[dupes ] First occurrence index: "
              << std::distance(dups.begin(), itvec) << std::endl;
    return (0);
}