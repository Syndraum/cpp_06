#ifndef CCLASS
# define CCLASS

#include "Base.hpp"

class C : public Base
{
public:

	C(void);
	C(C const & src);
	virtual ~C(void);
	C &	operator=(C const &rhs);

private:

};

#endif
