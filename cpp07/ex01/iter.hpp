#pragma once

#include <cstddef>

template <typename T, typename F>

void iter(T *array, std::size_t const len, F func)
{
	size_t i = 0;
	while (i < len)
	{
		func(array[i]);
		i++;
	}
}