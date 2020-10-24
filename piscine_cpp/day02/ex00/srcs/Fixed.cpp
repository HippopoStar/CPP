#include "Fixed.hpp"

/**
 * Non-member attribute(s) initialization
 */

int const	Fixed::_binary_point_pos = 8;

/**
 * Constructor(s) & Destructor(s)
 */

Fixed::Fixed(void) : _fixed_point_raw_val(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/**
 * Operator overload(s)
 */

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Assignement operator called" << std::endl;
	(*this)._fixed_point_raw_val = rhs.getRawBits();
	return (*this);
}

/**
 * Public method(s)
 */

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return ((*this)._fixed_point_raw_val);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	(*this)._fixed_point_raw_val = raw;
}

/**
 * Private method(s)
 */

