template <typename T>
Array<T>::Array() : m_data(NULL), m_size(0) {}

template <typename T>
Array<T>::Array(unsigned int n)
	: m_data(n ? new T[n]() : NULL), m_size(n) {}

template <typename T>
Array<T>::Array(const Array& other)
	: m_data(other.m_size ? new T[other.m_size]() : NULL), m_size(other.m_size)
{
	try
	{
		for (unsigned int i = 0; i < m_size; ++i)
			m_data[i] = other.m_data[i];
	}
	catch (...)
	{
		delete[] m_data;
		throw;
	}
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		Array	copy(other);

		swap(copy);
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] m_data;
}

template <typename T>
T&	Array<T>::operator[](std::size_t index)
{
	if (index >= m_size)
		throw std::out_of_range("Array index out of bounds");
	return m_data[index];
}

template <typename T>
const T&	Array<T>::operator[](std::size_t index) const
{
	if (index >= m_size)
		throw std::out_of_range("Array index out of bounds");
	return m_data[index];
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return m_size;
}

template <typename T>
void	Array<T>::swap(Array& other)
{
	T*				data = m_data;
	unsigned int	size = m_size;

	m_data = other.m_data;
	m_size = other.m_size;
	other.m_data = data;
	other.m_size = size;
}
