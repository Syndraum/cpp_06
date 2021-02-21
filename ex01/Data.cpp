#include "Data.hpp"

void * serialize(void)
{
	char * adress = new char[20];
	int i = -1;

	srand(time(0));
	while (++i < 8)
		adress[i] = 32 + rand() % 95;
	i = 7;
	while (++i < 12)
		adress[i] = rand() % 255;
	i = 11;
	while (++i < 20)
		adress[i] = 32 + rand() % 95;
	return adress;
}

Data * deserialize(void * raw)
{
	Data * data = new Data;
	char * cursor = reinterpret_cast<char*>(raw);
	int * pInt = reinterpret_cast<int*>(&cursor[8]);

	data->s1 = std::string(cursor, 8);
	data->n = *pInt;
	data->s2 = std::string(&cursor[12], 8);
	return data;
}

std::ostream & operator<<(std::ostream & o, Data const & data)
{
	o << "// DATA // " << data.s1 << " " << data.n << " " << data.s2 << std::endl;
	return o;
}


void	describre(void * raw)
{
	int i = -1;
	char * cursor = reinterpret_cast<char*>(raw);

	std::cout << "// RAW //  " << std::string(cursor, 20) << std::endl << "// INT //  ";
	while (++i < 8)
		std::cout << cursor[i];
	i = 7;
	std::cout << " ";
	while (++i < 12)
		std::cout << static_cast<int>(cursor[i]) << " ";
	i = 11;
	std::cout << " ";
	while (++i < 20)
		std::cout << cursor[i];
	std::cout << std::endl;
}
