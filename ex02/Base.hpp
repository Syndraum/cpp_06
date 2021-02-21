#ifndef BASE
# define BASE

#include <iostream>

class Base
{
public:

	virtual ~Base(void) {}

};

void identify_from_pointer(Base * p);
void identify_from_reference( Base & p);

#endif
