#ifndef ACLASS
# define ACLASS

#include "Base.hpp"

class A : public Base
{
public:

	A(void);
	A(A const & src);
	virtual ~A(void);
	A &	operator=(A const &rhs);

private:

};

#endif
