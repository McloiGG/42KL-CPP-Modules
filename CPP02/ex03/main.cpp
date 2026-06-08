#include "Point.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

bool	bsp( Point const a, Point const b, Point const c, Point const point);

float	inputFloat(std::string prompt)
{
	std::string	input;
	float	value;
	std::string	leftover;

	while ( true )
	{
		std::cout << prompt;
		std::getline( std::cin, input );
		std::stringstream	ss( input );
		if ( ss >> value && !( ss >> leftover ) )
			return value;
		else if ( std::cin.eof() )
		{
			std::cout << "\nEOF detected. Exiting." << std::endl;
			std::exit(1);
		}
		std::cout << "Invalid input. Please enter a valid floating-point number." << std::endl;
	}
}

int main()
{
	std::cout << "Enter the coordinates of the triangle's vertices and the point to check if the point is inside the triangle" << std::endl;
	std::cout << "Vertex a:" << std::endl;
	Point	a( inputFloat("\tCoordinate x: "), inputFloat("\tCoordinate y: ") );

	std::cout << "\nVertex b:" << std::endl;
	Point	b( inputFloat("\tCoordinate x: "), inputFloat("\tCoordinate y: ") );

	std::cout << "\nVertex c:" << std::endl;
	Point	c( inputFloat("\tCoordinate x: "), inputFloat("\tCoordinate y: ") );

	std::cout << "\nPoint:" << std::endl;
	Point	point( inputFloat("\tCoordinate x: "), inputFloat("\tCoordinate y: ") );

	std::cout << "Triangle's vertices: " << a << ", " << b << ", " << c << std::endl << "\nResults: ";

	if (Point::cross_product(a, b, c) == 0)
	{
		std::cout << "Vertices a, b, and c do not form a valid triangle." << std::endl;
		return 0;
	}

	if (bsp(a, b, c, point))
		std::cout << "The point is inside the triangle." << std::endl;
	else
		std::cout << "The point is not inside the triangle." << std::endl;
}
