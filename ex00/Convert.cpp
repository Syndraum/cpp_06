#include "Convert.hpp"

Convert::Convert(void) : _org(""), _string(""), _char(' '), _int(0), _float(0.0f), _double(0.0)
{
	for (size_t i = 0; i < 4; i++){
		_pointeur[i] = 0;
	}
}

Convert::Convert(char const *value) : _org(value), _string(value), _char(' '), _int(0), _float(0.0f), _double(0.0) 
{
	for (size_t i = 0; i < 4; i++){
		_pointeur[i] = 0;
	}
}

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
		throw ImposibleConvertion();
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
	while (_org[++i] && _org[++i] != 'f')
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
	std::cout << "char: " << _char << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << _float << std::endl;
	std::cout << "double: " << _double << std::endl;
	
}

void	Convert::printIs()
{
	std::cout << std::boolalpha << "is char ? " << isChar() << std::endl;
	std::cout << "is int ? " << isInt() << std::endl;
	std::cout << "is float ? " << isFloat() << std::endl;
	std::cout << "is double ? " << isDouble() << std::endl;
}

char			Convert::getChar(void) const
{
	return this->_char;
}

int				Convert::getInt(void) const
{
	return this->_int;
}

float			Convert::getFloat(void) const
{
	return this->_float;
}

double			Convert::getDouble(void) const
{
	return this->_double;
}
