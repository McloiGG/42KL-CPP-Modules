#include <iostream>
#include <cctype>
#include <string>

std::string& str_toupper(std::string& s)
{
	for (std::string::iterator it = s.begin(); it != s.end(); ++it)
		*it = static_cast<char>(std::toupper(static_cast<unsigned char>(*it)));
	return s;
}

std::string str_toupper_copy(std::string s)
{
	return str_toupper(s);
}

int main(int argc, char** argv)
{

	std::string result;

	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	for (int i = 1; i < argc; i++)
		result += str_toupper_copy(std::string(argv[i]));
	std::cout << result << std::endl;
}
