#include "Data.hpp"

int main()
{
	void * serial = serialize();
	Data * data = deserialize(serial);
	describre(serial);
	std::cout << std::endl << *data;
	delete[] reinterpret_cast<char*>(serial);
	delete data;
	return 0;
}