#pragma once
#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>

class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;
		void sortVector();
		void mergeInsertVector(std::vector<int> &arr);
		void binaryInsertVector(std::vector<int> &arr, int val, int end);

		void sortDeque();
		void mergeInsertDeque(std::deque<int> &arr);
		void binaryInsertDeque(std::deque<int> &arr,int val, int end);

		std::vector<int> jacobsthal(int n);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void parseInput(int argc, char **argv);
		void run();
};