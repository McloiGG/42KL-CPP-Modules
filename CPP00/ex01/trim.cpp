#include "trim.h"

std::string&	trim(std::string& s)
{
	const std::string		whitespace = " \f\n\r\t\v";
	std::string::size_type	first;
	std::string::size_type	last;

	first = s.find_first_not_of(whitespace);
	if (first == std::string::npos)
	{
		s.clear();
		return (s);
	}
	last = s.find_last_not_of(whitespace);
	s = s.substr(first, last - first + 1);
	return (s);
}

std::string trim_copy(std::string s)
{
	trim(s);
	return s;
}

std::string& trim_inner(std::string& s)
{
	const std::string	whitespace = " \f\n\r\t\v";
	std::string			result;
	bool 				pending_space = false;

	for (std::string::size_type i = 0; i < s.length(); ++i)
	{
		if (whitespace.find(s[i]) != std::string::npos)
		{
			if (!result.empty())
				pending_space = true;
		}
		else
		{
			if (pending_space)
				result += ' ';
			result += s[i];
			pending_space = false;
		}
	}
	s = result;
	return s;
}

std::string	trim_inner_copy(std::string s)
{
	trim_inner(s);
	return (s);
}
