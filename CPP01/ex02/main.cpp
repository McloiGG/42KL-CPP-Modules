# include <iostream>
# include <string>

static const char* MSG_COLOR = "\033[36m"; // cyan
static const char* MSG_RESET = "\033[0m";

void	printAddresses(std::string& str, std::string* ptr, std::string& ref)
{
	std::cout << "The memory address of the string variable: " << &str << std::endl;
	std::cout << "The memory address held by stringPTR: " << ptr << std::endl;
	std::cout << "The memory address held by stringREF: " << &ref << std::endl;
}

void	printValues(std::string& string, std::string* stringPTR, std::string& stringREF)
{
	std::cout << "The value of the string variable: " << string << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
}

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;
	printAddresses(string, stringPTR, stringREF);
	printValues(string, stringPTR, stringREF);
	std::cout << MSG_COLOR << "\nA reference is essentially an alias for an existing variable." << MSG_RESET << std::endl;
	std::cout << MSG_COLOR << "\nHere we create another string variable and assign it to stringREF." << MSG_RESET << std::endl;
	std::string anotherString = "ANOTHER STRING";
	stringREF = anotherString;
	std::cout << MSG_COLOR << "The value of the original string variable is modified through that reference:" << MSG_RESET << std::endl;
	std::cout << "\nThe value of the other string variable: " << anotherString << std::endl;
	printValues(string, stringPTR, stringREF);
	std::cout << MSG_COLOR << "\nHowever, the memory addresses of stringREF will still refer to the original variable it was initialized with/assigned to." << MSG_RESET << std::endl;
	std::cout << "The memory address of the other string variable: " << &anotherString << std::endl;
	printAddresses(string, stringPTR, stringREF);
	std::cout << MSG_COLOR << "This proves that the reference is still referring to the original variable instead of the other varaible I assigned to it." << MSG_RESET << std::endl;
	std::cout << MSG_COLOR << "\nThis is because a reference cannot be reassigned to refer to a different variable after it's intial one." << MSG_RESET;
	std::cout << MSG_COLOR << "Essentially, the reference is an alias for the original variable and any changes made to the reference will affect the original variable." << MSG_RESET << std::endl;
}
