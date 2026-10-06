#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array
{
private:
	T*				m_data;
	unsigned int	m_size;

	void	swap(Array& other);

public:
	Array();
	explicit Array(unsigned int n);
	Array(const Array& other);
	Array&	operator=(const Array& other);
	~Array();

	T&				operator[](std::size_t index);
	const T&		operator[](std::size_t index) const;
	unsigned int	size() const;
};

#include "Array.tpp"

#endif
