#include "Harl.hpp"
#include <iostream>

static void run_case(Harl &harl, const std::string &label, const std::string &level)
{
	std::cout << "=== " << label << " ===" << std::endl;
	std::cout << "Input: [" << level << "]" << std::endl;
	harl.complain(level);
	std::cout << std::endl;
}

int main()
{
	Harl harl;

	run_case(harl, "Valid level: DEBUG", "DEBUG");
	run_case(harl, "Valid level: INFO", "INFO");
	run_case(harl, "Valid level: WARNING", "WARNING");
	run_case(harl, "Valid level: ERROR", "ERROR");
	run_case(harl, "Edge case: empty string", "");
	run_case(harl, "Edge case: lowercase", "debug");
	run_case(harl, "Edge case: mixed case", "WaRnInG");
	run_case(harl, "Edge case: leading space", " INFO");
	run_case(harl, "Edge case: trailing space", "ERROR ");
	run_case(harl, "Edge case: unknown token", "WHATEVER");
	run_case(harl, "Edge case: near match", "WARN");
}
