#include <fstream>
#include <iostream>

int	main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <search> <replace>" << std::endl;
		return (1);
	}

	std::ifstream	file(argv[1]);
	std::string		s1(argv[2]);
	std::string		s2(argv[3]);
	std::string		line;

	if (file.fail()) // or !file also works, but not is_open() because it doesn't check for failbit and badbit flags
	{
		std::cerr << "Error: Could not open file " << argv[1] << std::endl;
		return (1);
	}
	if (s1.empty())
	{
		std::cerr << "Error: Search string cannot be empty." << std::endl;
		return (1);
	}

	std::ofstream	outfile((std::string(argv[1]) + ".replace").c_str());

	if (outfile.fail())
	{
		std::cerr << "Error: Could not create " << std::string(argv[1]) + ".replace" << std::endl;
		return (1);
	}
	while (std::getline(file, line))
	{
		std::string::size_type	pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outfile << line;
		if (!file.eof())
			outfile << std::endl;
	}
	if (file.bad()) // bad to check I/O errors, fail can be set by eof which would trigger false positive
	{
		std::cerr << "Error: An error occurred while reading the file." << std::endl;
		return (1);
	}
	if (outfile.fail())
	{
		std::cerr << "Error: An error occurred while writing to the file." << std::endl;
		return (1);
	}
	//The file objects are closed automatically when they go out of scope (RAII (Resource Acquisition Is Initialization)).
	//file.close();
	//outfile.close();
}
