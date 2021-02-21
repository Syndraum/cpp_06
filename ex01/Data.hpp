#ifndef DATA
# define DATA

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

std::ostream & operator<<(std::ostream & o, Data const & data);

void *	serialize(void);
Data *	deserialize(void * raw);
void	describre(void * raw);

#endif