#include "C.hpp"

C::C(void){}

C::C(C const & src)
{
	*this = src;
}

C::~C(void)
{
	
}

C &	C::operator=(C const & rhs)
{
	(void)rhs;
	return *this;
}
