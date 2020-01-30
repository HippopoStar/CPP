#include <iostream>
#include "Fraction.h"

int		pgcd(int a, int b)
{
	int		c;

	while (b > 0)
	{
		c = b;
		b = a % b;
		a = c;
	}
	return (a);
}

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

void		Fraction::display(std::ostream &stream) const
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

bool		Fraction::is_equal(const Fraction &b) const
{
	return ((m_numerator == b.m_numerator && m_denominator == b.m_denominator) ? true : false);
}

bool		Fraction::is_lower(const Fraction &b) const
{
	return ((m_numerator * b.m_denominator < m_denominator * b.m_numerator) ? true : false);
}

Fraction	&Fraction::operator+=(const Fraction &b)
{
	m_numerator = (m_numerator * b.m_denominator) + (b.m_numerator * m_denominator);
	m_denominator = m_denominator * b.m_denominator;
	return (*this);
}

Fraction	&Fraction::operator-=(const Fraction &b)
{
	m_numerator = (m_numerator * b.m_denominator) - (b.m_numerator * m_denominator);
	m_denominator = m_denominator * b.m_denominator;
	return (*this);
}

Fraction	&Fraction::operator*=(const Fraction &b)
{
	m_numerator = m_numerator * b.m_numerator;
	m_denominator = m_denominator * b.m_denominator;
	return (*this);
}

Fraction	&Fraction::operator/=(const Fraction &b)
{
	if (!(b.m_numerator == 0))
	{
		m_numerator = m_numerator * b.m_denominator;
		m_denominator = m_denominator * b.m_numerator;
	}
	else
	{
		m_numerator = 0;
		m_denominator = 1;
		std::cout << "Can not divide by 0" << std::endl;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, const Fraction &a)
{
	a.display(stream);
	return (stream);
}

bool		operator==(const Fraction &a, const Fraction &b)
{
	return (a.is_equal(b) ? true : false);
}

bool		operator!=(const Fraction &a, const Fraction &b)
{
	return (!(a == b) ? true : false);
}

bool		operator<(const Fraction &a, const Fraction &b)
{
	return (a.is_lower(b) ? true : false);
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
	(void)a;
}
