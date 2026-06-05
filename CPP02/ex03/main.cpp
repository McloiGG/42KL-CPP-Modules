#include "Point.hpp"
#include <sstream>
#include <cmath>

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
		std::cout << "Invalid input. Please enter a valid floating-point number." << std::endl;
	}
}

int main()
{
	std::cout << "Enter the coordinates of the triangle's vertices and the point to check if the point is inside the triangle:" << std::endl;

	std::cout << "\nVertex a:" << std::endl;
	Point	a( inputFloat("Coordinate x: "), inputFloat("Coordinate y: ") );
	std::cout << "Coordinates of a: " << a << std::endl;

	std::cout << "\nVertex b:" << std::endl;
	Point	b( inputFloat("Coordinate x: "), inputFloat("Coordinate y: ") );
	std::cout << "Coordinates of b: " << b << std::endl;

	std::cout << "\nVertex c:" << std::endl;
	Point	c( inputFloat("Coordinate x: "), inputFloat("Coordinate y: ") );
	std::cout << "Coordinates of c: " << c << std::endl;

	std::cout << "\nPoint:" << std::endl;
	Point	point( inputFloat("Coordinate x: "), inputFloat("Coordinate y: ") );
	std::cout << "Coordinates of point: " << point << std::endl;

	std::cout << "\nTriangle's vertices: " << a << ", " << b << ", " << c << std::endl;

	// check for coincident points
	if ((a.getX() == b.getX() && a.getY() == b.getY()) ||
		(a.getX() == c.getX() && a.getY() == c.getY()) ||
		(b.getX() == c.getX() && b.getY() == c.getY()))
	{
		std::cerr << "\nabc does not form a valid triangle." << std::endl;
		return 1;
	}

	// check collinearity via signed area (zero => collinear)
	float area2 = a.getX()*(b.getY()-c.getY())
			+ b.getX()*(c.getY()-a.getY())
			+ c.getX()*(a.getY()-b.getY());

	if (std::fabs(area2) < 1e-6f) {
		std::cerr << "\nabc does not form a valid triangle." << std::endl;
		return 1;
	}

	if (bsp(a, b, c, point))
		std::cout << "\nThe point is inside the triangle." << std::endl;
	else
		std::cout << "\nThe point is outside the triangle." << std::endl;
}
