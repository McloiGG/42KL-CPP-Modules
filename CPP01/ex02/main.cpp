# include <iostream>
# include <string>

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
	std::cout << "\nA reference is essentially an alias for an existing variable." << std::endl;
	std::cout << "\nHere we create another string variable and assign it to stringREF." << std::endl;
	std::string anotherString = "ANOTHER STRING";
	stringREF = anotherString;
	std::cout << "The value of the original string variable is modified through that reference:" << std::endl;
	std::cout << "\nThe value of the other string variable: " << anotherString << std::endl;
	printValues(string, stringPTR, stringREF);
	std::cout << "\nHowever, the memory addresses of stringREF will still refer to the original variable it was initialized with/assigned to." << std::endl;
	std::cout << "The memory address of the other string variable: " << &anotherString << std::endl;
	printAddresses(string, stringPTR, stringREF);
	std::cout << "This proves that the reference is still referring to the original variable instead of the other varaible I assigned to it." << std::endl;
	std::cout << "\nThis is because a reference cannot be reassigned to refer to a different variable after it's intial one." << std::endl;
}
