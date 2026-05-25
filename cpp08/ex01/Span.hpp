#pragma once
#include <vector>
#include <list>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <stdexcept>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;
	public:
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		void addNumber(int n);
		template <typename Iterator>
		void addRange(Iterator begin, Iterator end)
		{
			while(begin != end)
			{
				addNumber(*begin);
				++begin;
			}
		}
		int shortestSpan() const;
		int longestSpan() const;
};