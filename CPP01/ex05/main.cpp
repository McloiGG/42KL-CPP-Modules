#include "Harl.hpp"
#include <iostream>

static void run_case(Harl &harl, const std::string &label, const std::string &level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	static const char* MSG_COLOR = "\033[36m"; // cyan
	static const char* MSG_RESET = "\033[0m";

	std::cout << MSG_COLOR << "=== " << label << " ===" << MSG_RESET << std::endl;
	std::cout << MSG_COLOR << "Input: [" << level << "]" << MSG_RESET << std::endl;
	harl.complain(level);
	if (level != levels[0] && level != levels[1] && level != levels[2] && level != levels[3])
		std::cout << MSG_COLOR << std::endl << MSG_RESET;
}

int main()
{
	Harl harl;

	static const char* MSG_COLOR = "\033[36m"; // cyan
	static const char* MSG_RESET = "\033[0m";

	std::cout << MSG_COLOR << "=== VALID TESTS ===" << MSG_RESET << std::endl;
	run_case(harl, "DEBUG", "DEBUG");
	run_case(harl, "INFO", "INFO");
	run_case(harl, "WARNING", "WARNING");
	run_case(harl, "ERROR", "ERROR");
	std::cout << MSG_COLOR << "=== LOOP ===" << MSG_RESET << std::endl;
	for (int i = 0; i < 3; i++)
		harl.complain("DEBUG");
	std::cout << MSG_COLOR << std::endl << MSG_RESET;
	std::cout << MSG_COLOR << "=== INVALID TESTS ===" << MSG_RESET << std::endl;
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
