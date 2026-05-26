#include "MutantStack.hpp"

int main()
{
	std::cout << "=== MutantStack ===" << std::endl;
	MutantStack<int> mutestack;
	mutestack.push(5);
	mutestack.push(7);
	std::cout << "top: " << mutestack.top() << std::endl;

	std::cout << "size: " << mutestack.size() << std::endl;
	mutestack.pop();
	std::cout << "size: " << mutestack.size() << std::endl;
	mutestack.push(3);
	mutestack.push(33);
	mutestack.push(200);
	MutantStack<int>::iterator it = mutestack.begin();
	MutantStack<int>::iterator ite = mutestack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mutestack);
	std::cout << std::endl;
	    std::cout << "=== list ===" << std::endl;
    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(17);
    std::cout << "top: " << lst.back() << std::endl;

    lst.pop_back();
    std::cout << "size: " << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(1);

    std::list<int>::iterator it2  = lst.begin();
    std::list<int>::iterator ite2 = lst.end();

    ++it2;
    --it2;
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }

    std::cout << std::endl;
	MutantStack<int> empty;
    std::cout << "size: " << empty.size() << std::endl;
	MutantStack<int> copy(mutestack);
    std::cout << "copy top: " << copy.top() << std::endl;

	const MutantStack<int> cmstack(mutestack);
    MutantStack<int>::const_iterator cit  = cmstack.begin();
    MutantStack<int>::const_iterator cite = cmstack.end();
    std::cout << "const iter: ";
    while (cit != cite)
    {
        std::cout << *cit << " ";
        ++cit;
    }
    std::cout << std::endl;
    std::cout << std::endl;
	MutantStack<std::string> sstack;
    sstack.push("hello");
    sstack.push("world");
    sstack.push("42");
    MutantStack<std::string>::iterator sit = sstack.begin();
    while (sit != sstack.end())
    {
        std::cout << *sit << std::endl;
        ++sit;
    }

    return 0;
}