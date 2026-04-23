#include <iostream>
#include <cctype>
#include <string>

int main(int argc, char** argv)
{

	std::string result;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}

	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
		{
			unsigned char c = static_cast<unsigned char>(argv[i][j]);
			result += static_cast<char>(std::toupper(c));
		}
	}

	std::cout << result << '\n';
	return 0;
}