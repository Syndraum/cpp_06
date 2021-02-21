#ifndef BCLASS
# define BCLASS

#include "Base.hpp"

class B: public Base
{
public:

	B(void);
	B(B const & src);
	virtual ~B(void);
	B &	operator=(B const &rhs);

private:

};

#endif
