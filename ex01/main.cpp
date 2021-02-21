#include "Data.hpp"

int main()
{
	void * serial = serialize();
	Data * data = deserialize(serial);
	describre(serial);
	std::cout << *data;
	delete[] reinterpret_cast<char*>(serial);
	delete data;
	return 0;
}