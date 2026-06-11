#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq)
{

}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{

}

void PmergeMe::run()
{
	std::cout << "Before: ";
	size_t i = 0;
	while (i < _vec.size())
	{
		std::cout << " " << _vec[i];
		i++;
	}
	std::cout << std::endl;
	clock_t startVec = clock();
	sortVector();
	clock_t endVec = clock();
	// microseconds 
	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

	clock_t startDeq = clock();
	sortDeque();
	clock_t endDeq = clock();
	double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;
	std::cout << "After: ";
	i = 0;
	while (i < _vec.size())
	{
		std::cout << " " << _vec[i];
		i++;
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _vec.size()
		<< " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
		<< " elements with std::deque :" << timeDeq << " us" << std::endl;
}
// hi = position of paired major in chain
// val = value to insert
void PmergeMe::binaryInsertVector(std::vector<int> &chain, int val, int hi)
{
	int lo = 0;
	while (lo < hi)
	{
		int mid = (lo + hi) / 2;
		if (chain[mid] < val)
			lo = mid + 1;
		else
			hi = mid;
	}
	chain.insert(chain.begin() + lo, val);
}

void PmergeMe::binaryInsertDeque(std::deque<int>& chain, int val, int hi)
{
	int lo = 0;
	while (lo < hi)
	{
		int mid = (lo + hi) / 2;
		if (chain[mid] < val)
			lo = mid + 1;
		else
			hi = mid;
	}
	chain.insert(chain.begin() + lo, val);
}

void PmergeMe::sortVector()
{
	mergeInsertVector(_vec);
}

void PmergeMe::sortDeque()
{
	mergeInsertDeque(_deq);
}

void PmergeMe::parseInput(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string token(argv[i]);
		char *end = NULL;
		long val;

		if (token.empty())
			throw std::runtime_error("Error");
		for (size_t j = 0; j < token.size(); j++)
		{
			if (!std::isdigit(static_cast<unsigned char>(token[j])))
				throw std::runtime_error("Error");
		}
		val = std::strtol(token.c_str(), &end, 10);
		if (*end != '\0' || val <= 0 || val > INT_MAX)
			throw std::runtime_error("Error");
		int num = static_cast<int>(val);
		if (std::find(_vec.begin(), _vec.end(), num) != _vec.end())
			throw std::runtime_error("Error");
		_vec.push_back(num);
		_deq.push_back(num);
	}
	if (_vec.empty())
		throw std::runtime_error("Error");
}

std::vector<int> PmergeMe::jacobsthal(int n)
{
	std::vector<int> order;
	int prev = 1;
	int curr = 3;
	while (prev < n)
	{
		int end = curr;
		if (end > n)
			end = n;
		// insert from end down (descending within each group)
		for (int i = end; i > prev; i--)
			order.push_back(i - 1);
		int next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}
	// Returns insertion order indices
	return (order);
}

void PmergeMe::mergeInsertVector(std::vector<int> &array)
{
	int size = static_cast<int>(array.size());
	if (size <= 1)
		return ;

	// pair.first = mayor
	// pair.second = minor
	// straggler = leftover element
	std::vector< std::pair<int, int> > pairs;
	bool hasStraggler = (size % 2 != 0);
	int straggler = 0;
	int limit = size;

	if (hasStraggler)
	{
		straggler = array[size - 1];
		limit = size - 1;
	}
	for (int i = 0; i < limit; i += 2)
	{
		if (array[i] > array[i + 1])
			pairs.push_back(std::make_pair(array[i], array[i + 1]));
		else
			pairs.push_back(std::make_pair(array[i + 1], array[i]));
	}

	// to order the biggers doing recursivity
	std::vector<int> bigs;
	for (size_t i = 0; i < pairs.size(); i++)
		bigs.push_back(pairs[i].first);
	mergeInsertVector(bigs);

	std::vector<int> chain;
	std::vector<int> pend;
	for (size_t i = 0; i < bigs.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			// looking the minor of each pair
			// finding the pair
			if (pairs[j].first == bigs[i])
			{
				chain.push_back(pairs[j].first);
				pend.push_back(pairs[j].second);
				break ;
			}
		}
	}
	// insert pend at start
	chain.insert(chain.begin(), pend[0]);
	// insert the rest of numbers with jacobsthal
	std::vector<int> order = jacobsthal(static_cast<int>(pend.size()));
	for (size_t i = 0; i < order.size(); i++)
	{
		int index = order[i];
		// max index limit at biggers numbers
		std::vector<int>::iterator bound = std::find(chain.begin(), chain.end(), bigs[index]);
		int hi = static_cast<int>(bound - chain.begin());
		// insert pend[index] before bigs[index]
		binaryInsertVector(chain, pend[index], hi);
	}
	// insert the oleftover
	if (hasStraggler)
		binaryInsertVector(chain, straggler, static_cast<int>(chain.size()));
	array = chain;
}

void PmergeMe::mergeInsertDeque(std::deque<int> &array)
{
	int size = static_cast<int>(array.size());
	if (size <= 1)
		return ;

	std::deque< std::pair<int, int> > pairs;
	bool hasStraggler = (size % 2 != 0);
	int straggler = 0;
	int limit = size;

	if (hasStraggler)
	{
		straggler = array[size - 1];
		limit = size - 1;
	}
	for (int i = 0; i < limit; i += 2)
	{
		if (array[i] > array[i + 1])
			pairs.push_back(std::make_pair(array[i], array[i + 1]));
		else
			pairs.push_back(std::make_pair(array[i + 1], array[i]));
	}

	std::deque<int> bigs;
	for (size_t i = 0; i < pairs.size(); i++)
		bigs.push_back(pairs[i].first);
	mergeInsertDeque(bigs);

	std::deque<int> chain;
	std::deque<int> pend;
	for (size_t i = 0; i < bigs.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == bigs[i])
			{
				chain.push_back(pairs[j].first);
				pend.push_back(pairs[j].second);
				break ;
			}
		}
	}

	chain.insert(chain.begin(), pend[0]);
	std::vector<int> order = jacobsthal(static_cast<int>(pend.size()));
	for (size_t i = 0; i < order.size(); i++)
	{
		int index = order[i];
		std::deque<int>::iterator bound = std::find(chain.begin(), chain.end(), bigs[index]);
		int hi = static_cast<int>(bound - chain.begin());
		binaryInsertDeque(chain, pend[index], hi);
	}
	if (hasStraggler)
		binaryInsertDeque(chain, straggler, static_cast<int>(chain.size()));
	array = chain;
}
