#ifndef FRACTION_H
# define FRACTION_H

# include <iostream>

void			swap(int &a, int &b);
int				gcd(int a, int b);
int				lcm(int a, int b);

class			Fraction
{
	public:

	Fraction(void);
	Fraction(const int &numerator, const int &denominator = 1);
	~Fraction(void);

	void		print(std::ostream &stream) const;
	bool		eq(const Fraction &b) const;
	bool		lt(const Fraction &b) const;
	int			get_numerator(void) const;
	int			get_denominator(void) const;

	void		to_opposite(void);
	void		to_inverse(void);

	Fraction	&operator+=(const Fraction &b);
	Fraction	&operator-=(const Fraction &b);
	Fraction	&operator*=(const Fraction &b);
	Fraction	&operator/=(const Fraction &b);

	private:

	int			m_numerator;
	int			m_denominator;

	void		simplify(void);
};

std::ostream	&operator<<(std::ostream &stream, const Fraction &a);
bool			operator==(const Fraction &a, const Fraction &b);
bool			operator!=(const Fraction &a, const Fraction &b);
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
