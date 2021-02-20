#include "Convert.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{

	if (argc != 2)
		return 1;
	Convert convert(argv[1]);
	convert.detection();
	convert.display();
	return 0;
}
