#include "Convert.hpp"

Convert::Convert(void) : _org(""), _string(""), _char(' '), _int(0), _float(0.0f), _double(0.0) {}

Convert::Convert(char const *value) : _org(value), _string(value), _char(' '), _int(0), _float(0.0f), _double(0.0) {}

Convert::Convert(Convert const & src)
{
	*this = src;
}

Convert::~Convert(void)
{
	
}

Convert &	Convert::operator=(Convert const & rhs)
{
	if (this != &rhs){
		_org = rhs._org;
		_string = rhs._string;
		_char = rhs._char;
		_int = rhs._int;
		_float = rhs._float;
		_double = rhs._double;
	}
	return *this;
}

void	Convert::detection()
{
	if (isInt()){
		_int = stoi(_string);
		_char = static_cast<char>(_int);
		_float = static_cast<float>(_int);
		_double = static_cast<double>(_int);
	}
	else if (isChar()){
		_char = _org[0];
		_int = static_cast<int>(_char);
		_float = static_cast<float>(_char);
		_double = static_cast<double>(_char);
	}
	else if (isFloat()){
		_float = stof(_string);
		_int = static_cast<int>(_float);
		_char = static_cast<char>(_float);
		_double = static_cast<double>(_float);
	}
	else if (isDouble()){
		_double = stod(_string);
		_int = static_cast<int>(_double);
		_char = static_cast<char>(_double);
		_float = static_cast<float>(_double);
	}
	else
		throw NoConvertionfound();
}

bool	Convert::isChar() const
{
	int	i = 0;

	while (_org[i])
		++i;
	if (i == 1 && _org[0] >= ' ')
		return true;
	return false;
}

bool	Convert::isInt() const
{
	int	i = -1;

	if (_org[i+1] == '-')
		i++;
	if (_org[i + 1] == 0)
		return false;
	while (_org[++i])
	{
		if (_org[i] < '0' || _org[i] > '9')
			return false;
	}
	return true;
}

bool	Convert::isFloat() const
{
	int	i = -1;
	bool asDot = false;

	if (_string == "nanf" || _string == "-inff" || _string == "+inff")
		return true;
	if (_org[i+1] == '-')
		i++;
	while (_org[++i] && _org[i] != 'f')
	{
		if(_org[i] == '.'){
			if (asDot)
				return false;
			asDot = true;
		}
		else if (_org[i] < '0' || _org[i] > '9')
			return false;
	}
	if (_org[i+1] != 0 || !asDot)
		return false;
	return true;
}

bool	Convert::isDouble() const
{
	int	i = -1;
	bool asDot = false;

	if (_string == "nan" || _string == "-inf" || _string == "+inf")
		return true;
	if (_org[i+1] == '-')
		i++;
	while (_org[++i])
	{
		if(_org[i] == '.'){
			if (asDot)
				return false;
			asDot = true;
		}
		else if (_org[i] < '0' || _org[i] > '9')
			return false;
	}
	if (!asDot)
		return false;
	return true;
}

void	Convert::display() const
{
	std::cout << "char: ";
	try {
		std::cout << getChar() << std::endl;
	}
	catch(const std::exception& e){
		std::cout << e.what() << '\n';
	}
	std::cout << "int: ";
	try
	{
		std::cout << getInt() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "float: " << getFloat() << std::endl;
	std::cout << "double: " << getDouble() << std::endl;
	
}

void	Convert::printIs()
{
	std::cout << std::boolalpha << "is char ? " << isChar() << std::endl;
	std::cout << "is int ? " << isInt() << std::endl;
	std::cout << "is float ? " << isFloat() << std::endl;
	std::cout << "is double ? " << isDouble() << std::endl;
}

std::string		Convert::getChar(void) const
{
	std::stringstream ss;

	if (_float != _float || _double != _double)
		throw ImposibleConvertion();
	if (_char < ' ')
		throw NoDisplayable();
	ss << "'" <<_char << "'";
	return (ss.str());
}

std::string		Convert::getInt(void) const
{
	std::stringstream ss;

	if (_float != _float || _double != _double)
		throw ImposibleConvertion();
	ss << _int;
	return (ss.str());
}

std::string		Convert::getFloat(void) const
{
	std::stringstream ss;
	
	ss << _float;
	if (static_cast<float>(_int) == _float)
		ss << ".0";
	ss << "f";
	return (ss.str());
}

std::string		Convert::getDouble(void) const
{
	std::stringstream ss;
	ss << _double;
	if (static_cast<double>(_int) == _double)
		ss << ".0";
	return (ss.str());
}
