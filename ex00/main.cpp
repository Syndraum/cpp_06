#include "Convert.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{

	if (argc != 2)
		return 1;
	Convert convert(argv[1]);
	try
	{
		convert.detection();
	}
	catch(const Convert::NoConvertionfound& e)
	{
		std::cerr << "Conversion impossible" << '\n';
		return 2;
	}
	convert.display();
	return 0;
}
