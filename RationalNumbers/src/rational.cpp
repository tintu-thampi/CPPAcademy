#include "rational.h"
using namespace std;

Rational::Rational(int numerator, int denominator) : numer{numerator}, denom{denominator}
{
}

Rational::Rational(const Rational& copy) : numer{copy.numer}, denom{copy.denom}
{
}

Rational Rational::operator*(const Rational& other) const
{
    return Rational{numer * other.numer, denom * other.denom};
}

Rational operator+(int i, const Rational& r)
{
    return Rational{(i * r.denominator()) + r.numerator(), r.denominator()};
}

Rational Rational:: operator-(const Rational& other) const
{
    return Rational{numer * other.denom - denom * other.numer, denom * other.denom};
}

Rational Rational::operator+(const Rational& other) const
{
    return Rational{numer * other.denom + denom * other.numer, denom * other.denom};
}

Rational Rational::operator/(const Rational& other) const
{
    return Rational{numer * other.denom, denom * other.numer};
}

bool Rational::operator==(const Rational& other) const
{
    if (numer == other.numer && denom == other.denom)
        return true;
    else
        return false;
}

Rational operator+(const Rational& r,int i)
{
    return Rational{r.numerator() + i * r.denominator(), r.denominator()};
}

std::ostream& operator<<(std::ostream& os, const Rational& rational)
{
    os << rational.numer << "/" << rational.denom;
    return os;
}
