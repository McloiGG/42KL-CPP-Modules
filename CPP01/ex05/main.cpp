#include "Harl.hpp"
#include <iostream>

static void run_case(Harl &harl, const std::string &label, const std::string &level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	std::cout << "=== " << label << " ===" << std::endl;
	std::cout << "Input: [" << level << "]" << std::endl;
	harl.complain(level);
	if (level != levels[0] && level != levels[1] && level != levels[2] && level != levels[3])
		std::cout << std::endl;
}

int main()
{
	Harl harl;

	std::cout << "=== VALID TESTS ===" << std::endl;
	run_case(harl, "DEBUG", "DEBUG");
	run_case(harl, "INFO", "INFO");
	run_case(harl, "WARNING", "WARNING");
	run_case(harl, "ERROR", "ERROR");
	std::cout << "=== LOOP ===" << std::endl;
	for (int i = 0; i < 3; i++)
		harl.complain("DEBUG");
	std::cout << std::endl;
	std::cout << "=== INVALID TESTS ===" << std::endl;
	run_case(harl, "EMPTY STRING", "");
	run_case(harl, "LOWERCASE", "debug");
	run_case(harl, "MIXED CASE", "WaRnInG");
	run_case(harl, "LEADING SPACE", " INFO");
	run_case(harl, "TRAILING SPACE", "ERROR ");
	run_case(harl, "UNKNOWN TOKEN", "WHATEVER");
	run_case(harl, "NEAR MATCH", "WARN");
	run_case(harl, "TAB", "\tINFO");
	run_case(harl, "MIDDLE NULL", "WARN\0ING");
	run_case(harl, "NEWLINE", "ERROR\n");
}
