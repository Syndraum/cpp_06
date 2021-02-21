#include "A.hpp"

A::A(void){}

A::A(A const & src)
{
	*this = src;
}

A::~A(void)
{
	
}

A &	A::operator=(A const & rhs)
{
	(void)rhs;
	return *this;
}
