#ifndef FRACTION_H
# define FRACTION_H

#include <iostream>

int		pgcd(int a, int b);

class	Fraction
{
	public:

	Fraction(void);
	Fraction(const int &numerator, const int &denominator = 1);
	~Fraction(void);

	void		display(std::ostream &stream) const;
	bool		is_equal(const Fraction &b) const;
	bool		is_lower(const Fraction &b) const;

	Fraction	&operator+=(const Fraction &b);
	Fraction	&operator-=(const Fraction &b);
	Fraction	&operator*=(const Fraction &b);
	Fraction	&operator/=(const Fraction &b);

	private:

	int			m_numerator;
	int			m_denominator;
};

std::ostream	&operator<<(std::ostream &stream, const Fraction &a);
bool			operator==(const Fraction &a, const Fraction &b);
bool			operator<(const Fraction &a, const Fraction &b);
bool			operator>(const Fraction &a, const Fraction &b);
bool			operator<=(const Fraction &a, const Fraction &b);
bool			operator>=(const Fraction &a, const Fraction &b);
Fraction		operator+(const Fraction &a, const Fraction &b);
Fraction		operator-(const Fraction &a, const Fraction &b);
Fraction		operator*(const Fraction &a, const Fraction &b);
Fraction		operator/(const Fraction &a, const Fraction &b);
Fraction		operator-(const Fraction &a);

#endif
