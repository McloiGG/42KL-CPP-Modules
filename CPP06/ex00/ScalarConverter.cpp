#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <iostream>
#include <limits>
#include <sstream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

enum LiteralType
{
	INVALID,
	INT,
	FLOAT,
	DOUBLE
};

static void	printImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static bool	isSpecial(double n)
{
	return n != n || n == std::numeric_limits<double>::infinity() || n == -std::numeric_limits<double>::infinity();
}

static std::string	specialName(double n, const std::string& suffix)
{
	if (n != n)
		return "nan" + suffix;
	return (n < 0 ? "-inf" : "+inf") + suffix;
}

template <typename T>
static bool	fitsIn(double n)
{
	T	low = std::numeric_limits<T>::is_integer ? std::numeric_limits<T>::min() : -std::numeric_limits<T>::max();

	if (std::numeric_limits<T>::is_integer)
		n = n < 0 ? std::ceil(n) : std::floor(n);
	return n >= static_cast<double>(low) && n <= static_cast<double>(std::numeric_limits<T>::max());
}

template <typename T>
static std::string	formatDecimal(T value)
{
	std::ostringstream	stream;

	stream << value;
	std::string	result = stream.str();
	if (result.find_first_of(".eE") == std::string::npos)
		result += ".0";
	return result;
}

template <typename T>
static void	printConversions(T value)
{
	double	n = static_cast<double>(value);

	std::cout << "char: ";
	if (!fitsIn<char>(n))
		std::cout << "impossible";
	else if (!std::isprint(static_cast<unsigned char>(static_cast<char>(value))))
		std::cout << "Non displayable";
	else
		std::cout << '\'' << static_cast<char>(value) << '\'';

	fitsIn<int>(n) ? std::cout << "\nint: " << static_cast<int>(value) : std::cout << "\nint: impossible";

	std::cout << "\nfloat: ";
	if (isSpecial(n))
		std::cout << specialName(n, "f");
	else if (!fitsIn<float>(n))
		std::cout << "impossible";
	else
		std::cout << formatDecimal(static_cast<float>(value)) << 'f';

	std::cout << "\ndouble: " << (isSpecial(n) ? specialName(n, "") : formatDecimal(static_cast<double>(value))) << std::endl;
}

template <typename T>
static void	parseNumeric(const std::string& literal)
{
	std::istringstream	stream(literal);
	T					value;

	if (stream >> value)
	{
		printConversions(value);
		return;
	}

	std::string	decimal = literal;

	if (!decimal.empty() && (decimal[decimal.size() - 1] == 'f' || decimal[decimal.size() - 1] == 'F'))
		decimal.erase(decimal.size() - 1);

	std::istringstream	retry(decimal);
	double				big;

	(retry >> big) ? printConversions(big) : printImpossible();
}

static LiteralType	getNumeric(const std::string& literal)
{
	std::size_t	i = 0;
	bool		digits = false;
	bool		decimal = false;

	if (literal.empty())
		return INVALID;
	if (literal[i] == '+' || literal[i] == '-')
		++i;
	for (; i < literal.size() && std::isdigit(static_cast<unsigned char>(literal[i])); ++i)
		digits = true;
	if (i < literal.size() && literal[i] == '.')
	{
		decimal = true;
		++i;
		for (; i < literal.size() && std::isdigit(static_cast<unsigned char>(literal[i])); ++i)
			digits = true;
	}
	if (!digits)
		return INVALID;
	if (i < literal.size() && (literal[i] == 'e' || literal[i] == 'E'))
	{
		decimal = true;
		++i;
		if (i < literal.size() && (literal[i] == '+' || literal[i] == '-'))
			++i;
		std::size_t	start = i;
		for (; i < literal.size() && std::isdigit(static_cast<unsigned char>(literal[i])); ++i);
		if (i == start)
			return INVALID;
	}
	if (decimal && i + 1 == literal.size() && (literal[i] == 'f' || literal[i] == 'F'))
		return FLOAT;
	if (i != literal.size())
		return INVALID;
	return decimal ? DOUBLE : INT;
}

template <typename T>
static bool	parsePsuedo(const std::string& literal, const std::string& suffix)
{
	const T	inf = std::numeric_limits<T>::infinity();

	if (literal == "nan" + suffix)
		printConversions(std::numeric_limits<T>::quiet_NaN());
	else if (literal == "+inf" + suffix)
		printConversions(inf);
	else if (literal == "-inf" + suffix)
		printConversions(-inf);
	else
		return false;
	return true;
}

void	ScalarConverter::convert(const std::string& literal)
{
	if (literal.size() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])) && std::isprint(static_cast<unsigned char>(literal[0])))
	{
		printConversions(literal[0]);
		return;
	}
	if (parsePsuedo<float>(literal, "f") || parsePsuedo<double>(literal, ""))
		return;
	switch (getNumeric(literal))
	{
		case INT:
			parseNumeric<int>(literal);
			break;
		case FLOAT:
			parseNumeric<float>(literal);
			break;
		case DOUBLE:
			parseNumeric<double>(literal);
			break;
		default:
			printImpossible();
	}
}
