#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify_from_pointer(Base * p)
{
	A * a = dynamic_cast<A*>(p);
	B * b = dynamic_cast<B*>(p);
	C * c = dynamic_cast<C*>(p);

	if (a!=0)
		std::cout << "A";
	else if (b!=0)
		std::cout << "B";
	else if (c!=0)
		std::cout << "C";
	else
		std::cout << "Unknow type";
	std::cout << "\n";
	
}

int main()
{
	Base * p = new A();
	identify_from_pointer(p);
	delete p;
	p = new B();
	identify_from_pointer(p);
	delete p;
	p = new C();
	identify_from_pointer(p);
	delete p;
	p = new Base();
	identify_from_pointer(p);
	delete p;
	p = 0;
	identify_from_pointer(p);
	return 0;
}
