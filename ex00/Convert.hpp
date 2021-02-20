#ifndef CONVERT
# define CONVERT

#include <cstring>
#include <string>
#include <exception>
#include <iostream>

class Convert
{
	Convert(void);
public:
	class ImposibleConvertion : public std::exception{
		virtual const char* what() const throw(){
			return "impossible";
		}
	};
	class NoDisplayable : public std::exception{
		virtual const char* what() const throw(){
			return "No displayable";
		}
	};
	Convert(char const *value);
	Convert(Convert const & src);
	virtual ~Convert(void);
	Convert &	operator=(Convert const &rhs);

	char			getChar(void) const;
	int				getInt(void) const;
	float			getFloat(void) const;
	double			getDouble(void) const;

	void	detection();
	bool	isChar() const;
	bool	isInt() const;
	bool	isFloat() const;
	bool	isDouble() const;
	void	convertion();
	void	display() const;
	void	printIs();
private:
	char const *_org;
	std::string _string;
	char		_char;
	int			_int;
	float		_float;
	double		_double;
	char		_pointeur[4];
};

#endif
