#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n)
{

}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers)
{

}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span()
{

}

void Span::addNumber(int n)
{
	if (_numbers.size() >= _maxSize)
		throw std::runtime_error("Span is full");
	_numbers.push_back(n);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers");
	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());
	int shortest = 0;
	int diff = 0;
	size_t i = 1;
	shortest = sorted[1] - sorted[0];
	while (i < sorted.size() - 1)
	{
		diff = sorted[i + 1] - sorted[i];
		if (diff < shortest)
			shortest = diff;
		i++;
	}
	return (shortest);
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers");
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	return (max - min);
}
