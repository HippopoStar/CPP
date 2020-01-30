#include <iostream>
#include "Fraction.h"

void	swap(int &a, int &b)
{
	int		c;

	c = a;
	a = b;
	b = c;
}

/**
 * In the 2 following functions (gcd & lcm),
 * we assume that we already have "b > 0"
 */

int		gcd(int a, int b)
{
	int		c;

	if (a < 0)
	{
		a = -a;
	}
	if (a < b)
	{
		swap(a, b);
	}
	while (b > 0)
	{
		c = b;
		b = a % b;
		a = c;
	}
	return (a);
}

int		lcm(int a, int b)
{
	if (a < 0)
	{
		a = -a;
	}
	return (a * (b / gcd(a, b)));
}

/**
 * Constructor(s) & Destructor(s)
 */

Fraction::Fraction(void)
{
	m_numerator = 0;
	m_denominator = 1;
}

Fraction::Fraction(const int &numerator, const int &denominator)
{
	if (!(denominator == 0))
	{
		m_numerator = numerator;
		m_denominator = denominator;
		(*this).simplify();
	}
	else
	{
		m_numerator = 0;
		m_denominator = 1;
		std::cout << "Denominator can not take value 0" << std::endl;
	}
}

Fraction::~Fraction(void)
{

}

/**
 * Private method(s)
 */

void		Fraction::simplify(void)
{
	int		c;

	if (m_denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	if ((c = gcd(m_numerator, m_denominator)) > 1)
	{
		m_numerator = m_numerator / c;
		m_denominator = m_denominator / c;
	}
}

/**
 * Public method(s) - const
 */

void		Fraction::print(std::ostream &stream) const
{
	if (m_denominator == 1)
	{
		stream << m_numerator;
	}
	else
	{
		stream << m_numerator << '/' << m_denominator;
	}
}

bool		Fraction::eq(const Fraction &b) const
{
	return ((m_numerator == b.m_numerator && m_denominator == b.m_denominator) ? true : false);
}

bool		Fraction::lt(const Fraction &b) const
{
	return ((m_numerator * b.m_denominator < m_denominator * b.m_numerator) ? true : false);
}

/**
 * Public method(s) - accessors
 */

int			Fraction::get_numerator(void) const
{
	return (m_numerator);
}

int			Fraction::get_denominator(void) const
{
	return (m_denominator);
}

/**
 * Public method(s) - attributes modifiers
 */

void		Fraction::to_opposite(void)
{
	m_numerator = -m_numerator;
}

void		Fraction::to_inverse(void)
{
	if (!(m_numerator == 0))
	{
		swap(m_numerator, m_denominator);
		(*this).simplify();
	}
	else
	{
		std::cout << "Can not invert 0" << std::endl;
	}
}

/**
 * Public method(s) - assignement operators
 */

Fraction	&Fraction::operator+=(const Fraction &b)
{
	m_numerator = (m_numerator * b.m_denominator) + (b.m_numerator * m_denominator);
	m_denominator = m_denominator * b.m_denominator;
	(*this).simplify();
	return (*this);
}

Fraction	&Fraction::operator-=(const Fraction &b)
{
	m_numerator = (m_numerator * b.m_denominator) - (b.m_numerator * m_denominator);
	m_denominator = m_denominator * b.m_denominator;
	(*this).simplify();
	return (*this);
}

Fraction	&Fraction::operator*=(const Fraction &b)
{
	m_numerator = m_numerator * b.m_numerator;
	m_denominator = m_denominator * b.m_denominator;
	(*this).simplify();
	return (*this);
}

Fraction	&Fraction::operator/=(const Fraction &b)
{
	if (!(b.m_numerator == 0))
	{
		m_numerator = m_numerator * b.m_denominator;
		m_denominator = m_denominator * b.m_numerator;
		(*this).simplify();
	}
	else
	{
		m_numerator = 0;
		m_denominator = 1;
		std::cout << "Can not divide by 0" << std::endl;
	}
	return (*this);
}

/**
 * External function(s)
 */

std::ostream	&operator<<(std::ostream &stream, const Fraction &a)
{
	a.print(stream);
	return (stream);
}

/**
 * External function(s) - comparison operators
 */

bool		operator==(const Fraction &a, const Fraction &b)
{
	return (a.eq(b) ? true : false);
}

bool		operator!=(const Fraction &a, const Fraction &b)
{
	return (!(a == b) ? true : false);
}

bool		operator<(const Fraction &a, const Fraction &b)
{
	return (a.lt(b) ? true : false);
}

bool		operator>(const Fraction &a, const Fraction &b)
{
	return (!(a < b || a == b) ? true : false);
}

bool		operator<=(const Fraction &a, const Fraction &b)
{
	return ((a < b || a == b) ? true : false);
}

bool		operator>=(const Fraction &a, const Fraction &b)
{
	return (!(a < b) ? true : false);
}

/**
 * External function(s) - arithmetic operators
 */

Fraction	operator+(const Fraction &a, const Fraction &b)
{
	Fraction	a_copy(a);

	a_copy += b;
	return (a_copy);
}

Fraction	operator-(const Fraction &a, const Fraction &b)
{
	Fraction	a_copy(a);

	a_copy -= b;
	return (a_copy);
}

Fraction	operator*(const Fraction &a, const Fraction &b)
{
	Fraction	a_copy(a);

	a_copy *= b;
	return (a_copy);
}

Fraction	operator/(const Fraction &a, const Fraction &b)
{
	Fraction	a_copy(a);

	a_copy /= b;
	return (a_copy);
}

Fraction	operator-(const Fraction &a)
{
	Fraction	a_copy(a);

	a_copy.to_opposite();
	return (a_copy);
}
