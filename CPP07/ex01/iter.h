#pragma once
#ifndef ITER_H
# define ITER_H

#include <cstddef>

template <typename T, typename F>
void	iter(T* array, const std::size_t length, F func)
{
	for (std::size_t i = 0; i < length; ++i)
		func(array[i]);
}

#endif
