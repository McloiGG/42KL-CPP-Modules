#include "Harl.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	Harl		harl;
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = 0;

	if (argc != 2)
	{
		std::cerr << "Usage: ./harlFilter <level>" << std::endl;
		return (1);
	}
	while (i < 4 && levels[i] != argv[1])
		i++;
	switch (i)
	{
	case 0:
		harl.complain("DEBUG");
	case 1:
		harl.complain("INFO");
	case 2:
		harl.complain("WARNING");
	case 3:
		harl.complain("ERROR");
		break;
	default:
		harl.complain("FALLBACK");
	}
}
