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

void identify_from_reference(Base & p)
{
	try
	{
		A & a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A";
	}
	catch(const std::exception& e)
	{
		try
		{
			B & b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B";
		}
		catch(const std::exception& e)
		{
			try
			{
				C & c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C";
			}
			catch(const std::exception& e)
			{
				std::cerr << "Unknow type";
			}
			
		}
		
	}
	std::cout << "\n";
	
}

int main()
{
	Base base = Base();
	A a = A();
	B b = B();
	C c = C();

	Base * p = new Base();
	std::cout << "////// TEST POINTER //////" << std::endl;
	identify_from_pointer(&a);
	identify_from_pointer(&b);
	identify_from_pointer(&c);
	identify_from_pointer(&base);
	identify_from_pointer(0);
	identify_from_pointer(p);
	delete p;
	p = new A();
	identify_from_pointer(p);
	delete p;
	p = new B();
	identify_from_pointer(p);
	delete p;
	p = new C();
	identify_from_pointer(p);
	delete p;

	std::cout << "////// TEST REFERENCE //////" << std::endl;
	identify_from_reference(a);
	identify_from_reference(b);
	identify_from_reference(c);
	identify_from_reference(base);
	return 0;
}
