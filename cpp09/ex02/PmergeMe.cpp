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
	int i = 1;
	size_t j = 0;
	long val = 0;
	while (i < argc)
	{
		std::string token(argv[i]);
		while (j < token.size())
		{
			if (!isdigit(token[j]))
				throw std::runtime_error("Error");
			j++;
		}
		val = std::atol(token.c_str());
		if (val <= 0 || val > 2147483647)
			throw std::runtime_error("Error");
		_vec.push_back(static_cast<int>(val));
		_deq.push_back(static_cast<int>(val));
		i++;
	}
	if (_vec.empty())
		throw std::runtime_error("Error");
}

std::vector<int> PmergeMe::jacobsthal(int n)
{
	std::vector<int> seq;

	seq.push_back(0);
	seq.push_back(1);
	while (true)
	{
		int next = seq[seq.size() - 1] + 2 * seq[seq.size() - 2];
		if (next >= n)
			break;
		seq.push_back(next);
	}
	return (seq);
}

void PmergeMe::mergeInsertVector(std::vector<int> &array)
{
	int size = array.size();
	if (size <= 1)
		return ;
	// form pairs and separate biggers in 'a' and minors in 'b'
	std::vector<int> a;
	std::vector<int> b;
	bool hasStraggler = (size % 2 != 0);
	int straggler = 0;
	int limit = size;
	size_t i = 0;
	if (hasStraggler)
	{
		straggler = array[size - 1];
		limit = size - 1;
	}
	while (i < (size_t)limit)
	{
		if (array[i] > array[i + 1])
		{
			a.push_back(array[i]);
			b.push_back(array[i + 1]);
		}
		else
		{
			a.push_back(array[i + 1]);
			b.push_back(array[i]);
		}
		i += 2;
	}
	// recursivity with biggers
	mergeInsertVector(a);
	// Construct the principal chain with b[0] at the start
	std::vector<int> chain;
	chain.push_back(b[0]);
	i = 0;
	while (i < a.size())
	{
		chain.push_back(a[i]);
		i++;
	}
	// Insert the rest of b with orden jacobsthal
	std::vector<int> jseq = jacobsthal(b.size());
	std::vector<bool> inserted(b.size(), false);
	inserted[0] = true;
	size_t j = 2;
	while (j < jseq.size())
	{
		int from = jseq[j];
		int to = jseq[j - 1];
		int k = from;
		while(k > to)
		{
			if (k < (int)b.size() && !inserted[k])
			{
				int hi = 0;
				int m = (int)b.size() - 1;
				while (m >= 0)
				{
					if (chain[m] == a[k])
					{
						hi = m;
						break;
					}
					m--;
				}
				binaryInsertVector(chain, b[k], hi + 1);
				inserted[k] = true;
			}
			k--;
		}
		j++;
	}
	// insert the 'b' were left outsite of Jacobsthal range
	size_t k = 1;
	while (k < b.size())
	{
		if (!inserted[k])
			binaryInsertVector(chain, b[k], (int)chain.size());
		k++;
	}
	// insert the rest if exist
	if (hasStraggler)
		binaryInsertVector(chain, straggler, (int)chain.size());
	array = chain;
}

void PmergeMe::mergeInsertDeque(std::deque<int> &array)
{
	int size = array.size();
	if (size <= 1)
		return ;

	std::deque<int> a;
	std::deque<int> b;
	bool	hasStraggler = (size % 2 != 0);
	int		straggler = 0;
	int		limit = size;
	size_t	i = 0;

	if (hasStraggler)
	{
		straggler = array[size - 1];
		limit = size - 1;
	}
	while (i < (size_t)limit)
	{
		if (array[i] > array[i + 1])
		{
			a.push_back(array[i]);
			b.push_back(array[i + 1]);
		}
		else
		{
			a.push_back(array[i + 1]);
			b.push_back(array[i]);
		}
		i += 2;
	}

	mergeInsertDeque(a);

	std::deque<int> chain;
	chain.push_back(b[0]);
	i = 0;
	while (i < a.size())
	{
		chain.push_back(a[i]);
		i++;
	}

	std::vector<int>	jseq = jacobsthal(b.size());
	std::vector<bool>	inserted(b.size(), false);
	inserted[0] = true;

	size_t j = 2;
	while (j < jseq.size())
	{
		int from = jseq[j];
		int to   = jseq[j - 1];
		int k    = from;
		while (k > to)
		{
			if (k < (int)b.size() && !inserted[k])
			{
				int hi = 0;
				int m  = (int)chain.size() - 1;
				while (m >= 0)
				{
					if (chain[m] == a[k])
					{
						hi = m;
						break;
					}
					m--;
				}
				binaryInsertDeque(chain, b[k], hi + 1);
				inserted[k] = true;
			}
			k--;
		}
		j++;
	}

	size_t k = 1;
	while (k < b.size())
	{
		if (!inserted[k])
			binaryInsertDeque(chain, b[k], (int)chain.size());
		k++;
	}

	if (hasStraggler)
	{
		binaryInsertDeque(chain, straggler, (int)chain.size());
	}
	array = chain;
}
