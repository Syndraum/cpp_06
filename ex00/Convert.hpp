#ifndef CONVERT
# define CONVERT

# include <cstring>
# include <string>
# include <exception>
# include <iostream>
# include <sstream>

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
	class NoConvertionfound : public std::exception{
		virtual const char* what() const throw(){
			return "No conversion";
		}
	};
	Convert(char const *value);
	Convert(Convert const & src);
	virtual ~Convert(void);
	Convert &	operator=(Convert const &rhs);

	std::string		getChar(void) const;
	std::string		getInt(void) const;
	std::string		getFloat(void) const;
	std::string		getDouble(void) const;

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
};

#endif
