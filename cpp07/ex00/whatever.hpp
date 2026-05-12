#pragma once

template <typename T>

void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T const &min(T const &a, T const &b)
{
	if (b <= a)
		return (b);
	else
		return (a);
}

template <typename T>
T const &max(T const &a, T const &b)
{
	if (b >= a)
		return (b);
	else
		return (a);
}