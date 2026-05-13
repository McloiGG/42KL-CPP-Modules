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

	if (!file)
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

	if (!outfile)
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
		outfile << line << std::endl;
	}
	//The file objects are closed automatically when they go out of scope (RAII (Resource Acquisition Is Initialization)).
	//file.close();
	//outfile.close();
}
